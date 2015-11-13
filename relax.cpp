#include "relax.h"

Relax::Relax() {
  for (int i = 0; i < a_.size(); ++i) 
    b_.push_back(1 - a_[i]);
  c_.push_back(a_);
  c_.push_back(b_);

  cout << "a: " << endl;
  for (int i = 0; i < a_.size(); ++i) {
    cout << a_[i] << "\t";
    if ((i+1)%5 == 0) cout << endl;
  }
  cout << "---------------------------------------" << endl;
  for (int i = 0; i < b_.size(); ++i) {
    cout << b_[i] << "\t";
    if ((i+1)%5 == 0) cout << endl;
  }
  cout << "---------------------------------------" << endl;
}

bool Relax::c(int i, int j) {
  return 
    (j != i) && (
      (j >= (i-n_-1) && j <= (i-n_+1)) ||
      (j >= i-1 && j <= i+1) ||
      (j >= (i+n_-1) && j <= (i+n_+1))
    );
}

float Relax::q(int j, int i, int l) {
  float result = 0;
  int n = c_.size();
  for (int k = 0; k < n; ++k) {
    vector<float> next = c_[k];
    result += (r_[l][k] * next[j]);
  }
  return result;
}

float Relax::Q(int i, int l) {
  float result = 0;
  int n = a_.size();
  for (int j = 0; j < n; ++j) 
    result += (c(i, j) * q(j, i, l) );
  return result;
}

float Relax::p_next(int i, int l) {
  float bottom;
  vector<float> next = c_[l];
  float top = next[i] * Q(i, l);
  int n = c_.size();
  for (int k = 0; k < n; ++k) {
    vector<float> next = c_[k];
    bottom += next[i] * Q(i, k);
  } 
  return top ? (top / bottom) : 0;
}

int main() {
  Relax *r = new Relax();
  vector<float> q_new;
  int l = 0;
  r->p_next(0,0);
  for (int i=0; i<25; ++i) {
    cout << setprecision(4) << (r->p_next(i, l)) << "\t";
    if ((i+1)%5==0) cout << endl;
  }
  delete r;
 
}
