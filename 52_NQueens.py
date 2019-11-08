class Solution:

    @staticmethod
    def safe(queens,x,y):
        for i in range(x):
            if queens[i][y] == 'Q':
                return False
        for j in range(y):
            if queens[x][j] == 'Q':
                return False
        i = x - 1
        j = y - 1
        while i >= 0 and j >= 0:
            if queens[i][j] == 'Q':
                return False
            i -= 1
            j -= 1

        i = x - 1
        j = y + 1
        while i >= 0 and j < len(queens):
            if queens[i][j] == 'Q':
                return False
            i -= 1
            j += 1
        return True

    @staticmethod
    def solve(n,queens,k,answer,x):
        if k == 0:
            answer.append(queens.copy())
            return
        else:
            for i in range(x+1,n):
                for j in range(0,n):
                    if Solution.safe(queens,i,j):
                        queens[i] = "."*j + 'Q' + '.'*(n-j-1)
                        Solution.solve(n,queens,k-1,answer,x+1)
                        queens[i] = "."*n;
                return
            return

    def solveNQueens(self, n):
        queens = ['.' * n for i in range(0,n) ]
        answer = []
        Solution.solve(n,queens,n,answer,-1)
        return answer
