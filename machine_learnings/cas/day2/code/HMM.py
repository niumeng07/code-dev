
# coding: utf-8

# ### 介绍隐马尔科夫模型，一个HMM模型包含三个主要的参数
# - A: 状态间的转移参数（矩阵）
# - B：状态与观察值之间的转移参数（矩阵）
# - PI: 初始状态概率向量
# #### HMM的计算涉及到如下三个方面
# - 概率计算问题：给定模型和观察序列，计算观察序列出现的概率
# - 训练问题：估计模型参数
# - 预测问题：给定模型和观察序列，预测其状态信息

# In[2]:




import numpy as np
from util.utils import *


# In[3]:


class HMM():
    '''隐马尔科夫模型，模型包括三部分参数
    A: 状态间的转移参数（矩阵）
    B：状态与观察值之间的转移参数（矩阵）
    PI: 初始状态概率向量'''

    def __init__(self, state_num, obser_num, A=None, B=None, PI=None):
        self.state_num = state_num
        self.obser_num = obser_num
        if A is not None:
            self.A = A
        else:
            self.A = normalize(np.ones((state_num, state_num)))
        if B is not None:
            self.B = B
        else:
            self.B = normalize(np.ones((state_num, obser_num)))
        if PI is not None:
            self.PI = PI
        else:
            self.PI = np.full(state_num, 1.0 / state_num)
        print "A：\n", self.A
        print "B：\n", self.B
        print "PI：\n", self.PI

    
    # 估计参数
    def fit(self, state_seqs, obser_seqs):
        # 计算初始概率
        # self.PI = np.zeros((self.state_num,))
        self.PI = np.full(self.state_num, 1.0 / 100)
        for s in [x[0] for x in state_seqs]:
            self.PI[s] += 1.0
        self.PI /= np.sum(self.PI)
        # 计算状态转移概率和状态生成观察值概率
        # self.A = np.zeros((self.state_num, self.state_num))
        # self.B = np.zeros((self.state_num, self.obser_num))
        self.A = np.full((self.state_num, self.state_num), 1.0 / 100)
        self.B = np.full((self.state_num, self.obser_num), 1.0 / 100)
        for state_seq, obser_seq in zip(state_seqs, obser_seqs):
            for i in range(len(state_seq)-1):
                self.A[state_seq[i], state_seq[i+1]] += 1.0
            for s, o in zip(state_seq, obser_seq):
                self.B[s, o] += 1.0
        self.A = normalize(self.A)
        self.B = normalize(self.B)
        print "A：\n", self.A
        print "B：\n", self.B
        print "PI：\n", self.PI
    
    def baum_welch(self):
        pass

    
    # 概率估计，计算一个观察序列出现的概率
    def prob_comp(self, obser_seq):
        hist_prob_s = np.zeros(self.state_num)
        # 初始状态
        for state in range(self.state_num):
            hist_prob_s[state] = self.PI[state] * self.B[state][obser_seq[0]]
        for t in range(1, len(obser_seq)):
            new_prob_s = np.zeros(self.state_num)
            for curr_state in range(self.state_num):
                curr_prob = 0.0
                for last_state in range(self.state_num):
                    curr_prob += hist_prob_s[last_state] * self.A[last_state][curr_state]
                new_prob_s[curr_state] = curr_prob * self.B[curr_state][obser_seq[t]]
            hist_prob_s = new_prob_s
        return np.sum(hist_prob_s)

    
    # 解码，给定一个观察序列，求解最可能的状态序列，即，维特比算法
    def predict(self, obser_seq):
        n = len(obser_seq)
        max_prob_ts = np.zeros((n, self.state_num))
        max_prob_paths = list()
        # 初始化
        for state in range(self.state_num):
            max_prob_ts[0][state] = self.PI[state] * self.B[state][obser_seq[0]]
        max_prob_paths.append([0] * self.state_num)
        # 开始递推
        for t in range(1, n):
            best_path = []
            for state in range(self.state_num):
                curr_max, max_state = -100, -1
                for last_state in range(self.state_num):
                    prob = max_prob_ts[t-1][last_state] * self.A[last_state][state] *                            self.B[state][obser_seq[t]]
                    if prob > curr_max:
                        curr_max, max_state = prob, last_state
                max_prob_ts[t][state] = curr_max
                best_path.append(max_state)
            max_prob_paths.append(best_path)
        max_prob = np.max(max_prob_ts[n-1])
        print "最佳状态概率：", max_prob
        best_path = []
        last_state = np.argmax(max_prob_ts[n-1])
        best_path.append(last_state)

        for t in range(n-1, 0, -1):
            last_state = max_prob_paths[t][last_state]
            best_path.append(last_state)
        return [x for x in reversed(best_path)]


# In[4]:


A = [[0.5, 0.2, 0.3],
     [0.3, 0.5, 0.2],
     [0.2, 0.3, 0.5]]
B = [[0.5, 0.5],
     [0.4, 0.6],
     [0.7, 0.3]]
PI = [0.2, 0.4, 0.4]
hmm = HMM(3, 2, A, B, PI)


# In[9]:


obser_seq = [0, 1, 0]
print "模型生成观察序列的概率：", hmm.prob_comp(obser_seq)


# In[10]:


obser_seq = [0, 1, 0]
print "观察序列对应的最优状态序列：",'\t'.join(map(str, hmm.predict(obser_seq)))

