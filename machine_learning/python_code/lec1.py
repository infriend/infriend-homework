import numpy as np# number python
import matplotlib.pyplot as plt  # matrix plot libray   as: 混名，记成 plt
# add: + multiply: *  scalar: 源于scale 权系数 
# scalar multiplication:  数乘运算
v = [1,2]
w = np.array([3, 4])
v = np.array(v) # array: 数组
u = 3*w + 4*v # linear combination: add + mul
# draw : 画图
# dot: 内积，  书上就是用. 来表示
u2 = np.dot(v, w) 
u3 = v[0] * w[0] + v[1] * w[1]
u4 = 1*3 + 2 * 4
# length: norm ||v|| 
# ^ 表示 幂   a^2 = a*a, 在python里是用 a**2
a = 3
print(a**3) # a的三次方
len_of_v = np.sqrt(v[0]**2 + v[1]**2)
norm_of_v = np.sqrt(np.dot(v, v))
print(len_of_v)
print(norm_of_v)

A = np.array([[1,2],[3,4]])
b = np.array([6, 4])
x = np.linalg.solve(A, b) # 调用库函数  已更正
plt.quiver(0, 0, 1, 1)