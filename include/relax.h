#ifndef RELAX_H
#define RELAX_H

#include <bits/stdc++.h>

using namespace std;

class Relax {
  public:
    // Takes in array of pixels and compatibility coefficients.
    Relax(vector<float> a, vector< vector<int> > r);
    ~Relax();
    bool c(int i, int j);
    float Q(int i, int l);
    float q(int j, int i, int l);
    float p_next(int i, int l);
    int get_n();
  private:
    int n_;
    vector<float> a_, b_;
    vector< vector<float> > c_;
    vector< vector<int> > r_;
};

#endif /* RELAX_H */
