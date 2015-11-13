#ifndef RELAX_H
#define RELAX_H

#include <bits/stdc++.h>

using namespace std;

class Relax {
  public:
    // Takes in array of pixels and compatibility coefficients.
    Relax(vector<float> a, vector< vector<int> > r);
    ~Relax();
    int N = 25;
    bool c(int i, int j);
    float Q(int i, int l);
    float q(int j, int i, int l);
    float p_next(int i, int l);
  private:
    int n_ = 5;
    vector<float> a_, b_;
    vector< vector<float> > c_;
    vector< vector<int> > r_;
    bool l_[2] = {
      true, false
    };
};

#endif /* RELAX_H */
