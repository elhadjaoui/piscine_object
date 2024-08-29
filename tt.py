
# def Solution(path: list[list[str]]) -> str:
#     ins = set()
#     outs = set()
#     for a, b in path:
#         ins.add(a)
#         outs.add(b)
#     return list(outs - ins)[0]
# def Solution(matrix: list[list[int]]) -> bool:
#     first = sorted(matrix[0])
#     for i in range(1, len(matrix)): # O(m)
#             if sorted(matrix[i]) != first: # O(nlogn)
#                 return False
#     return True
# Time complexity: O(m*n * logn)

# def Solution(s1: str, s2: str) -> bool:
#     dict1 = {}
#     for i,e in enumerate(s1):
#         if e != s2[i]:
#             dict1[e] = i
#     if len(dict1) == 2 or len(dict1) == 0:
#         return True
#     return False
#     print(dict1)
       
#     # return sorted(s1) == sorted(s2)
def Solution(rectangles: list[list[int]]) -> int:
    count = 0
    lenghts = []
    for a,b in rectangles:
        if a <= b:
            lenghts.append(a)
        else:
            lenghts.append(b) 
    
    return  len([i for i in lenghts if i == max(lenghts)])

def main():
    rectangles = [[5,8], [3,9], [5,12], [16,5]]
    print(Solution(rectangles))

if __name__ == "__main__":
    main()