#ifndef RELAX_H
#define RELAX_H

#include <bits/stdc++.h>

using namespace std;

class Relax {
  public:
    Relax();
    int n_ = 5;
    bool c(int i, int j);
    float Q(int i, int l);
    float q(int j, int i, int l);
    float p_next(int i, int l);
  private:
    vector<float> a_ = {
      0.0, 0.0, 0.0, 0.0, 0.0,
      0.0, 0.1, 0.1, 0.1, 0.0,
      0.0, 0.1, 1.0, 0.1, 0.0,
      0.0, 0.1, 0.1, 0.1, 0.0,
      0.0, 0.0, 0.0, 0.0, 0.0
    };
    vector<float> b_;
    vector< vector<float> > c_;
    int r_[2][2] = {
      {2, 1},
      {1, 1}
    };
    bool l_[2] = {
      true, false
    };

};

#endif /* RELAX_H */
