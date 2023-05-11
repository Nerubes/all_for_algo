import matplotlib.pyplot as plt
import numpy as np

grid = [10000, 20000, 30000, 40000, 50000, 60000, 70000, 80000, 90000, 100000]

with open("data/sort_creation", "r") as sort, open("data/avl_creation", "r") as avl, open("data/hash_creation") as hash :
    sort_data = [float(i) for i in sort.read().split("\n")[:-1]]
    avl_data = [float(i) for i in sort.read().split("\n")[:-1]]
    hash_data = [float(i) for i in sort.read().split("\n")[:-1]]
    p = plt.figure(figsize=(16, 9))
    plt.title("Создание")
    plt.xlable("")
    plt.ylable("")
    plt.plot(grid, sort_data, label="sorted array")
    plt.plot(grid, avl_data, lable="avl tree")
    plt.plot(grid, hash_data, lable="hash table")
    plt.legend()
    plt.savefig("plots/cretion.png")