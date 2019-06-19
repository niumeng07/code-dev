from sklearn.metrics import roc_auc_score
import numpy
import random

y_test_positive = [1.0 for i in range(1000000)]
y_pred_positive = [random.random() + 0.2 for i in range(len(y_test_positive))]
y_test_negtive = [0.0 for i in range(1000000)]
y_pred_negtive = [random.random() - 0.2 for i in range(len(y_test_negtive))]

y_test = y_test_negtive + y_test_positive
y_pred = y_pred_negtive + y_pred_positive

auc_score = roc_auc_score(y_test,y_pred)
print auc_score

price = [random.random() * 100 for i in range(2000000)]

y_test2 = [ int(x) for x in list(numpy.array(y_test) * numpy.array(price))]
y_pred2 = list(numpy.array(y_pred) * numpy.array(price))

auc_score2 = roc_auc_score(y_test2, y_pred2)
print auc_score2

#label*price->label
#pctr*price->predict
