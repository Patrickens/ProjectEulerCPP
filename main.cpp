#include <iostream>
#include <sstream>
#include <math.h>
#include <typeinfo>
#include <list>
#include <bits/stdc++.h>
#include <fstream>



int problem1() {
    int sum = 0;
    for (int i = 0; i < 1000; i++){
        if (((i % 3) == 0) || ((i % 5) == 0)){
            sum += i;
        }
    }
    return sum;
}

int problem2() {
    int max = 4000000, x_1 = 0, x_2 = 1, fib = 1, sum = 0;
    while(fib <= max)
    {
        if(fib % 2 == 0){
            sum += fib;
        }

        x_1 = x_2;
        x_2 = fib;
        fib = x_1 + x_2;
    }
    return sum;
}

int problem3(){
    long long i;
    long long n = 600851475143;

    for(i = 3; i <= n; i += 2) {
        while(n % i == 0) {
            n /= i;
        }

        if (n == 1) break;
    }
    return i;
}


int reverse(int num){
    int reversed = 0;
    int rem;
    while (num != 0)
    {
        rem = num % 10;
        reversed = reversed * 10 + rem;
        num /= 10;
    }
    return reversed;
}

int problem4(){
    int num,rev;
    int max = 0;
    for (int i = 999; i > 100; i--) {
        for (int j = 999; j > 100; j--) {
            num = i*j;
            rev = reverse(num);
            if ((rev == num) && (max<num)){
                max=num;
            }
        }
    }
    return max;
}

int problem5(){
    bool t = true;
    int num = 20, add = 20;
    int rest;
    while (t){
        rest = 0;
        for (int i=1; i < add + 1; i++){
            rest += num%i;
        }
        if (rest == 0){
            break;
        }
        num += add;
    }
    return num;
}

int problem6(){
    int s1 = 0, s2 = 0;
    for (int i; i<101; i++){
        s1+=i*i;
        s2+=i;
    }
    return s2*s2 - s1;
}

int problem7(){
    int primeNo = 10001, num = 5, pindex = 3;
    int primes[primeNo] = {0};

    primes[0]=2;
    primes[1]=3;
    primes[2]=5;

    while (primes[primeNo-1]==0){
        for (int i = 0; i<pindex; i++){
            if (num%primes[i]==0){
                num += 2;
                break;
            }
            if (i == pindex-1){
                primes[pindex] = num;
                pindex += 1;
            }
        }
    }
    return primes[pindex-1];
}

unsigned long long int problem8(){
    // Improve when encountering 0
    int digits = 1000;
    int lenProd = 13;
    unsigned long long int maxProd = 0;
    unsigned long long int Prod;
    int prod[lenProd] = {0};

    char charNum[digits] =
    "73167176531330624919225119674426574742355349194934"
    "96983520312774506326239578318016984801869478851843"
    "85861560789112949495459501737958331952853208805511"
    "12540698747158523863050715693290963295227443043557"
    "66896648950445244523161731856403098711121722383113"
    "62229893423380308135336276614282806444486645238749"
    "30358907296290491560440772390713810515859307960866"
    "70172427121883998797908792274921901699720888093776"
    "65727333001053367881220235421809751254540594752243"
    "52584907711670556013604839586446706324415722155397"
    "53697817977846174064955149290862569321978468622482"
    "83972241375657056057490261407972968652414535100474"
    "82166370484403199890008895243450658541227588666881"
    "16427171479924442928230863465674813919123162824586"
    "17866458359124566529476545682848912883142607690042"
    "24219022671055626321111109370544217506941658960408"
    "07198403850962455444362981230987879927244284909188"
    "84580156166097919133875499200524063689912560717606"
    "05886116467109405077541002256983155200055935729725"
    "71636269561882670428252483600823257530420752963450";

    int j, num;
    for (int i = 0; i < digits; i++){
        Prod = 1;
        num = charNum[i] - 48;
        j = i%lenProd;
        prod[j] = num;
        for (int i = 0; i < lenProd; i++){
            Prod *= prod[i];
        }
        if (Prod > maxProd){
            std::cout << Prod << std::endl;
            maxProd = Prod;
        }
    }
    return maxProd;
}

unsigned int problem9(){
    unsigned int prod;
    int sum = 1000,k,ii,jj,kk;
    for (int i = 1; i <sum; i++){
        for (int j = 1; j < sum - i; j++){
            k = sum - i - j;
            ii = i*i;
            jj = j*j;
            kk = k*k;
            if (kk == ii + jj){
                return i*j*k;
            }
        }
    }
}


std::vector<unsigned long long int> sieveEratosthenes(unsigned long long int max){
    double dobMax = (double)max;
    bool numbers[max+1];
    memset(numbers,true,sizeof(numbers));
    numbers[0]=numbers[1]=false;
    for(unsigned long long int i = 2;
        i <= (unsigned long long int)sqrt(dobMax)+1;
        ++i){
        if(numbers[i]){
            for(unsigned long long int j = i;
                j <= max/i;
                ++j){
                numbers[j*i]=false;
            }
        }
    }

    long long int numPrimes = (unsigned long long int)(dobMax / log(dobMax));
    std::vector<unsigned long long int> primes{};
    primes.push_back(2);

    // and check only odd numbers here,
    // no other even number can be set
    for (unsigned long long int i = 3; i <= max; i += 2) {
        if (numbers[i]) {
            primes.push_back(i);
        }
    }
    /*
    for (std::vector<unsigned long long int>::iterator it = primes.begin();
         it != primes.end();
         ++it){
        std::cout << *it << std::endl;
    }
    */
    std::cout << primes.back();
    return primes;
}

unsigned long long int problem10(){
    const long long int max = 2000000;
    bool numbers[max];
    memset(numbers,true,sizeof(numbers));
    numbers[0]=numbers[1]=false;
    for(long long int i = 2; i <= (int)sqrt((double)max)+1; ++i){
        if(numbers[i]){
            for(long long int j=i;j<=max/i;++j){
                numbers[j*i]=false;
            }
        }
    }
    unsigned long long int result = 0;
    for (unsigned long int i=0; i<max-1; i++){
        if (numbers[i]){
            result += i;
        }
    }
    return result;
}

unsigned long int problem11(){
    std::ifstream in ("Problem11Matrix.txt");

    if (!in) {
        std::cout << "Cannot open file.\n";
        return 0;
    }

    const int size = 20, len = 4;
    int matrix[size][size];
    int i,j, iter;
    for (i = 0; i < size; i++) {
        for (j = 0; j < size; j++) {
            in >> matrix[i][j];
        }
    }

    in.close();

    unsigned long int max = 0;
    std::vector<unsigned long int> niks = {1,1,1,1,1,1};
    for (i = 0; i < 17; i++) {
        for (j = 0; j < 17; j++) {
            niks = {1,1,1,1,1,1};
            for (iter = 0; iter < 4; iter++){
                niks[0] *= matrix[i][j+iter]; // row
                niks[1] *= matrix[i+iter][j]; // col
                niks[2] *= matrix[i+iter][j+iter]; // diag1 down
                niks[3] *= matrix[i+3-iter][j+iter]; // dieg2 up
                if (j > 13){
                    niks[4] *= matrix[i+iter][j+len-1]; // endcol
                }
                if (i > 13){
                    niks[5] *= matrix[i+len-1][j+iter]; // endrow
                }
            }
            for (iter = 0; iter < 6; iter++){
                //std::cout << niks[iter] << std::endl;
                if (niks[iter] > max){
                    max = niks[iter];
                }
            }

        }
    }
    return max;
}

unsigned long int myPow(unsigned long int x, int p) {
    if (p == 0) return 1;
    if (p == 1) return x;
    return x * myPow(x, p-1);
}

unsigned long int problem12(){
    const long long int max = 1000000;
    sieveEratosthenes(max);

    return 0;
    bool numbers[max];
    memset(numbers,true,sizeof(numbers));
    numbers[0]=numbers[1]=false;
    for(long long int i = 2; i <= (int)sqrt((double)max)+1; ++i){
        if(numbers[i]){
            for(long long int j=i;j<=max/i;++j){
                numbers[j*i]=false;
            }
        }
    }

    unsigned long long int result = 0;
    unsigned long int primes[5000]; // first 5000 primes
    primes[0] = 2;
    int j = 1;
    for (unsigned long int i=0; i<max+1; i++){
        if (numbers[i]){
            std::cout << i << std::endl;
            primes[j] = i;
            j++;
            if (j==5001){
                break;
            }
        }
    }



    int i = 1, numDiv = 0, exp;
    unsigned long long int triNum;
    unsigned long int prime;
    while (true){
        triNum += i;
        i++;
        numDiv = exp =0;
        for (j=0; primes[j] < (int)(triNum/2+1); j++){
            prime = primes[j];
            while (myPow(prime, j) < triNum/2+1){
                if (i==0){break;}
            }
        }
        return 0;

    }
}

int problem13(){
    std::ifstream in ("Problem13Number.txt");

    if (!in) {
        std::cout << "Cannot open file.\n";
        return 0;
    }
    int i = 0, j = 0, M = 100, N = 50;
    //int matrix[M][N];
    int array[N] = {0};
    std::string line;
    while (in >> line)
    {
        for (j = 0; j < N; j++){
            //matrix[i][j] = line[j] - '0';
            array[j] += line[j] - '0';
        }
        i++;
    }
    in.close();

    int num, rest, prev = 0;
    std::string result = "";
    for (j = N-1; j >= 0; j--){
        array[j] += prev;
        num = array[j];
        rest = num % 10;
        prev = (num - rest)/10;
        if (j <= 9){
            result += rest + '0';
            if (j == 0){
                std::string last = std::to_string(prev);
                result += last;
            }
        }
    }

    std::reverse(result.begin(),result.end());
    result = result.substr(0,10);
    std::cout << result << std::endl;
    return 0;
}

int main(){
    unsigned long int a = problem12();
    //std::cout << a << std::endl;
    return 0;
}