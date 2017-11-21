
# coding: utf-8

# ### Python使用Gaussian Mixture Models
# ### 使用sklearn包提供的GMM类

# In[2]:




import numpy as np
import pylab as pl
from sklearn import mixture


get_ipython().magic(u'matplotlib inline')


# In[3]:


def data_loader():
    samples = list()
    centers = [(-1.0, 0.0), (1.0, 0.0),
               (0.0, -1.0), (0.0, 1.0)]
    for center in centers:
        samples.extend(zip(np.random.normal(center[0], 0.25, 100),
                           np.random.normal(center[1], 0.25, 100)))
    return samples

cluster_num = 4
instances = data_loader()


# In[4]:


gmm = mixture.GMM(cluster_num)
gmm.fit(instances) # 估计模型参数


# In[5]:


print gmm.weights_
print gmm.means_
print gmm.covars_


# In[6]:


# 对某个样本进行聚类类别指派
def assign(inst, _gmm):
    return _gmm.predict(inst)


# In[7]:


basic_colors = ['r', 'g', 'b', 'y']
basic_markers = ['+', 'o', '*', '^']
def plot_points(points, assigns=None, colors=None, markers=None):
    if assigns is not None:
        colors = [basic_colors[i] for i in assigns]
        markers = [basic_markers[i] for i in assigns]
    if colors is None or markers is None:
        colors = ['r' for _ in points]
        markers = ['+' for _ in points]
    for p, c, m in zip(points, colors, markers):
        pl.scatter(p[0], p[1], c=c, marker=m)
    pl.title('dataset with %d clusters and known outcomes.' % cluster_num)
    pl.show()


# In[10]:


labels = gmm.predict(instances)
plot_points(instances, labels)

