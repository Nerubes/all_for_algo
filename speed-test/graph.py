import matplotlib.pyplot as plt
import numpy as np

grid = []

i = 50000

while i <= 1000000 :
    grid.append(i)
    i += 50000

with open("data/sort_creation", "r") as sort, open("data/avl_creation", "r") as avl, open("data/hash_creation", "r") as hash :
    sort_data = [float(i) for i in sort.read().split("\n")[:-1]]
    avl_data = [float(i) for i in avl.read().split("\n")[:-1]]
    hash_data = [float(i) for i in hash.read().split("\n")[:-1]]
    p = plt.figure(figsize=(16, 9))
    plt.title("Создание")
    plt.xlabel("Количество элементов")
    plt.ylabel("Секунды")
    plt.plot(grid, sort_data, label="sorted array")
    plt.plot(grid, avl_data, label="avl tree")
    plt.plot(grid, hash_data, label="hash table")
    plt.legend()
    plt.savefig("plots/cretion.png")

with open("data/sort_find", "r") as sort, open("data/avl_find", "r") as avl, open("data/hash_find", "r") as hash :
    sort_data = [float(i) for i in sort.read().split("\n")[:-1]]
    avl_data = [float(i) for i in avl.read().split("\n")[:-1]]
    hash_data = [float(i) for i in hash.read().split("\n")[:-1]]
    p = plt.figure(figsize=(16, 9))
    plt.title("Поиск")
    plt.xlabel("Количество элементов")
    plt.ylabel("Секунды")
    plt.plot(grid, sort_data, label="sorted array")
    plt.plot(grid, avl_data, label="avl tree")
    plt.plot(grid, hash_data, label="hash table")
    plt.legend()
    plt.savefig("plots/find.png")

with open("data/sort_find_random", "r") as sort, open("data/avl_find_random", "r") as avl, open("data/hash_find_random", "r") as hash :
    sort_data = [float(i) for i in sort.read().split("\n")[:-1]]
    avl_data = [float(i) for i in avl.read().split("\n")[:-1]]
    hash_data = [float(i) for i in hash.read().split("\n")[:-1]]
    p = plt.figure(figsize=(16, 9))
    plt.title("Поиск случайных")
    plt.xlabel("Количество элементов")
    plt.ylabel("Секунды")
    plt.plot(grid, sort_data, label="sorted array")
    plt.plot(grid, avl_data, label="avl tree")
    plt.plot(grid, hash_data, label="hash table")
    plt.legend()
    plt.savefig("plots/find_random.png")

with open("data/sort_delete", "r") as sort, open("data/avl_delete", "r") as avl, open("data/hash_delete", "r") as hash :
    sort_data = [float(i) for i in sort.read().split("\n")[:-1]]
    avl_data = [float(i) for i in avl.read().split("\n")[:-1]]
    hash_data = [float(i) for i in hash.read().split("\n")[:-1]]
    p = plt.figure(figsize=(16, 9))
    plt.title("Удаление всего")
    plt.xlabel("Количество")
    plt.ylabel("Секунды")
    plt.plot(grid, sort_data, label="sorted array")
    plt.plot(grid, avl_data, label="avl tree")
    plt.plot(grid, hash_data, label="hash table")
    plt.legend()
    plt.savefig("plots/delete.png")

with open("data/avl_remove", "r") as avl, open("data/hash_remove", "r") as hash :
    avl_data = [float(i) for i in avl.read().split("\n")[:-1]]
    hash_data = [float(i) for i in hash.read().split("\n")[:-1]]
    p = plt.figure(figsize=(16, 9))
    plt.title("Удаление элемента")
    plt.xlabel("Количество")
    plt.ylabel("Секунды")
    plt.plot(grid, avl_data, label="avl tree")
    plt.plot(grid, hash_data, label="hash table")
    plt.legend()
    plt.savefig("plots/remove.png")