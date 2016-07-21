//
// Created by Margaux Lhommet on 7/6/16.
//

#ifndef REVISIONS_DIVERS_H
#define REVISIONS_DIVERS_H



int repeatedNumber(const vector<int> &A) {
    int n = A.size()/3;
    map<int, int> count;
    for (const auto & val : A){
        ++count[val];
        if (count[val] > n)
            return val;
    }
    return -1;
}


vector<int> lszero(vector<int> &A) {
    map<int, int> m;
    int sum=0;
    int imin=-1, imax=-1;
    int maxLength = 0;
    for (int i=0; i<A.size(); ++i){
        sum += A[i];

        if (A[i] == 0 && maxLength<1){
            imin=i;
            imax=i;
            maxLength=1;
        }

        if (sum == 0){
            imin=0;
            imax=i;
            maxLength=i+1;
        }

        if (m.find(sum) != m.end()){
            if (i-m[sum] > maxLength){
                imin=m[sum]+1;
                imax=i;
                maxLength=i-m[sum];
            }
        }
        else{
            m[sum]=i;
        }
        cout<<i<<": "<< sum << " imin: "<< imin<<" imax: "<<imax<<endl;
    }
    if (imin==-1) return vector<int>();
    else{
        vector<int> res;
        for (int i=imin;i<=imax;++i)
            res.push_back(A[i]);
        return res;
    }

}

vector<int> equal(vector<int> &A) {
    vector<int> res;
    int n=A.size();

    for (int a=0; a<n-2; ++a){
        for (int b=a+1; b<n; ++b){
            for (int c=a+1; c<n-1; ++c){
                if (c!=b)
                    for (int d=c+1; d<n; ++d){
                        if (d!=b)
                        if (A[a]+A[b] == A[c]+A[d]) {
                            return {a, b, c, d};
                        }
                    }
            }
        }
    }
    return res;
}

#endif //REVISIONS_DIVERS_H
