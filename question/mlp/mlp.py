"""
doc
"""
import os   # pylint: disable=unused-import
import sys  # pylint: disable=unused-import
import numpy as np

FEATURE_NUM = 2
EMBEDDING_SIZE = 2
BATCH_SIZE = 10

label = np.array([0, 1, 1, 0, 0, 0,  0,  0,  0,  0 ])
data = np.array([[1,2], [2,3], [2,3], [2,2], [2,1], [1,3], [1,3], [1,3], [1,3], [1,3] ])
def embedding_layer(feature_list):
    pass

feature_embeddings = []

for i in range(FEATURE_NUM):
    feature_embeddings.append(np.random.rand(EMBEDDING_SIZE))

print(feature_embeddings)
feature_embeddings_concat = np.concatenate(feature_embeddings)
print(feature_embeddings_concat)

HIDDEN_LAYER1_SIZE = 4
HIDDEN_LAYER1_W = np.random.rand(HIDDEN_LAYER1_SIZE)
