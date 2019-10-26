#!coding: utf-8

# In[1]:


from itertools import chain
import nltk
from sklearn.metrics import classification_report, confusion_matrix
from sklearn.preprocessing import LabelBinarizer
import sklearn
import pycrfsuite

print(sklearn.__version__)


# ## 使用CoNLL 2000 数据构建NP抽取系统 to build a NER system
# - 使用NLTK内部提供的CoNLL2000语料

# In[2]:


nltk.corpus.conll2000.fileids()


# In[3]:


get_ipython().run_cell_magic(u'time', u'',
                             u"train_sents = list(nltk.corpus.conll2000.iob_sents('train.txt'))\ntest_sents = list(nltk.corpus.conll2000.iob_sents('test.txt'))")


# 原始数据格式，方便提取特征

# In[4]:


train_sents[0]


# ## 特征模板

# In[5]:


def word2features(sent, i):
    word = sent[i][0]
    postag = sent[i][1]
    features = [
        'bias',
        'word.lower=' + word.lower(),
        'word[-3:]=' + word[-3:],
        'word[-2:]=' + word[-2:],
        'word.isupper=%s' % word.isupper(),
        'word.istitle=%s' % word.istitle(),
        'word.isdigit=%s' % word.isdigit(),
        'postag=' + postag,
        'postag[:2]=' + postag[:2],
    ]
    if i > 0:
        word1 = sent[i-1][0]
        postag1 = sent[i-1][1]
        features.extend([
            '-1:word.lower=' + word1.lower(),
            '-1:word.istitle=%s' % word1.istitle(),
            '-1:word.isupper=%s' % word1.isupper(),
            '-1:postag=' + postag1,
            '-1:postag[:2]=' + postag1[:2],
        ])
    else:
        features.append('BOS')

    if i < len(sent)-1:
        word1 = sent[i+1][0]
        postag1 = sent[i+1][1]
        features.extend([
            '+1:word.lower=' + word1.lower(),
            '+1:word.istitle=%s' % word1.istitle(),
            '+1:word.isupper=%s' % word1.isupper(),
            '+1:postag=' + postag1,
            '+1:postag[:2]=' + postag1[:2],
        ])
    else:
        features.append('EOS')

    return features


def sent2features(sent):
    return [word2features(sent, i) for i in range(len(sent))]


def sent2labels(sent):
    return [label for token, postag, label in sent]


def sent2tokens(sent):
    return [token for token, postag, label in sent]


# 特征示例

# In[6]:


sent2features(train_sents[0])[0]


# 抽取特征

# In[7]:


get_ipython().run_cell_magic(u'time', u'',
                             u'X_train = [sent2features(s) for s in train_sents]\ny_train = [sent2labels(s) for s in train_sents]\n\nX_test = [sent2features(s) for s in test_sents]\ny_test = [sent2labels(s) for s in test_sents]')


# ## 模型训练
# - 构建模型
# - 导入学习数据

# In[8]:


get_ipython().run_cell_magic(u'time', u'',
                             u'trainer = pycrfsuite.Trainer(verbose=False)\n\nfor xseq, yseq in zip(X_train, y_train):\n    trainer.append(xseq, yseq)')


# 设置训练参数：使用L-BFGSsu算法(默认值)并用Elastic Net进行正则化（本质就是L1和L2一起用）

# In[9]:


trainer.set_params({
    'c1': 1.0,   # coefficient for L1 penalty
    'c2': 1e-3,  # coefficient for L2 penalty
    'max_iterations': 50,  # stop earlier

    # include transitions that are possible, but not observed
    'feature.possible_transitions': True
})


# In[10]:


# 模型训练的参数
trainer.params()


# Train the model:

# In[11]:


get_ipython().run_cell_magic(u'time', u'', u"trainer.train('conll2000-np.crfsuite')")


# 训练模型保存到问句中

# In[12]:


get_ipython().system(u'ls -lh ./conll2000-np.crfsuite')


# 查看模型训练情况：使用logparser查看。

# In[13]:


trainer.logparser.last_iteration


# logparser记录的其他信息

# In[14]:


print len(trainer.logparser.iterations), trainer.logparser.iterations[-2]


# ## 模型预测
# - 创建模型
# - 导入模型文件

# In[15]:


tagger = pycrfsuite.Tagger()
tagger.open('conll2000-np.crfsuite')


# 对一个句子进行标注

# In[16]:


example_sent = test_sents[0]
print(' '.join(sent2tokens(example_sent)))

print "预测标签:", ' '.join(tagger.tag(sent2features(example_sent)))
print "真实标签:  ", ' '.join(sent2labels(example_sent))


# ## 模型评估

# In[17]:


def bio_classification_report(y_true, y_pred):
    """
    Classification report for a list of BIO-encoded sequences.
    It computes token-level metrics and discards "O" labels.
    
    Note that it requires scikit-learn 0.15+ (or a version from github master)
    to calculate averages properly!
    """
    lb = LabelBinarizer()
    y_true_combined = lb.fit_transform(list(chain.from_iterable(y_true)))
    y_pred_combined = lb.transform(list(chain.from_iterable(y_pred)))

    tagset = set(lb.classes_) - {'O'}
    tagset = sorted(tagset, key=lambda tag: tag.split('-', 1)[::-1])
    class_indices = {cls: idx for idx, cls in enumerate(lb.classes_)}

    return classification_report(
        y_true_combined,
        y_pred_combined,
        labels=[class_indices[cls] for cls in tagset],
        target_names=tagset,
    )


# 对测试集中所有数据进行预测

# In[18]:


get_ipython().run_cell_magic(
    u'time', u'', u'y_pred = [tagger.tag(xseq) for xseq in X_test]')


# 按照各类标签类型进行评价

# In[19]:


print(bio_classification_report(y_test, y_pred))
