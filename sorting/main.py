def swap(lis, index_a, index_b):
    temp = lis[index_a]
    lis[index_a] = lis[index_b]
    lis[index_b] = temp


def selection_sort(lis):
    length = len(lis)
    for i in range(length):
        minimum_index = i
        for j in range(i + 1, length):
            if lis[j] < lis[minimum_index]:
                minimum_index = j
        swap(lis, i, minimum_index)


if __name__ == '__main__':
    nums = [3, 7, 8, 1, 9, 30000, -5]
    selection_sort(nums)
    print(nums)
