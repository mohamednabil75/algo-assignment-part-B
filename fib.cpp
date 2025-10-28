#include<iostream>
using namespace std;

class fib{
private:
    void multiply2by2(int A[2][2], int B[2][2]){
        int a = A[0][0]*B[0][0] + A[0][1]*B[1][0];
        int b = A[0][0]*B[0][1] + A[0][1]*B[1][1];
        int c = A[1][0]*B[0][0] + A[1][1]*B[1][0];
        int d = A[1][0]*B[0][1] + A[1][1]*B[1][1];
        
        A[0][0] = a;
        A[0][1] = b;
        A[1][0] = c;
        A[1][1] = d;
    }
    
    void power(int A[2][2], int n){
        if (n == 1 || n == 0){
            return;
        }
        int tempMatrix[2][2] = {{1, 1},{1, 0}};
        power(A, n/2);
        // cout << "1";
        multiply2by2(A, A);

        if (n % 2 != 0){
            multiply2by2(A, tempMatrix);
        }
        

    }
    

    public:
    int recursion(int fib){
        if (fib == 0 || fib == 1){
            return 1;
        }
        return recursion(fib - 1) + recursion(fib - 2); 
    }
    int divide(int n){ //
        if(n == 0 || n == 1){
            return 1;
        }
        int F[2][2] = {{1, 1}, {1, 0}};
        power(F, n);
        return F[0][1];
    }
    int dynamic(int fib){
        int prev0 = 1, prev1 = 1; // 1 1 2 3 5
        if (fib == 0 || fib == 1){
            return prev0;
        }
        int temp;
        for (int i = 2; i <= fib; i++){
            temp = prev0 + prev1;
            prev0 = prev1;
            prev1 = temp;
        }
        return temp;
        
    }
};

int main(){ // 1 1 2 3 5 8 13 21 34 55 89 [F(0) = 1 not F(0) = 0]
    fib Fib;
    cout << "Welcom to Fibonacci Program here are some test cases: \n";
    cout << "Recursive:\nF(0) = " << Fib.recursion(0) << "\nF(4) = " << Fib.recursion(4) << "\nF(6) = " << Fib.recursion(6) << "\nF(3) = " << Fib.recursion(3) ;
    cout << "\nDivide and conquer(matrix):\nF(0) = " << Fib.divide(0) << "\nF(4) = " << Fib.divide(4) << "\nF(9) = " << Fib.divide(9) << "\nF(3) = " << Fib.divide(3) ;
    cout << "\nDynamic Programming(bottom-top method):\nF(0) = " << Fib.dynamic(0) << "\nF(10) = " << Fib.dynamic(10) << "\nF(7) = " << Fib.dynamic(7) << "\nF(3) = " << Fib.dynamic(3) ;
}