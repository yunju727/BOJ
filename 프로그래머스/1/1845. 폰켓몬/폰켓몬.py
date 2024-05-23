def solution(nums):
    key_nums = set(nums)
    answer = len(key_nums)
    N = len(nums)
    if answer >= (N/2):
        return N/2
    else:
        return answer