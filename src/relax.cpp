#include "relax.h"

Relax::Relax(vector<float> a, vector< vector<int> > r) : a_(a), r_(r) {
  for (size_t i = 0; i < a_.size(); ++i) 
    b_.push_back(1 - a_[i]);
  c_.push_back(a_);
  c_.push_back(b_);
  n_ = sqrt(a.size());

  cout << "---------------------------------------" << endl;
}

Relax::~Relax() {
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

int Relax::get_n() {
  return pow(n_,2);
}

int main() {

  vector< vector<int> > r_1 = {
    {1, 1},
    {1, 1}
  };

  vector< vector<int> > r_2 = {
    {2, 1},
    {1, 1}
  };

  vector<float> a_1 = {
    0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.1, 0.1, 0.1, 0.0,
    0.0, 0.1, 0.9, 0.0, 0.0,
    0.0, 0.1, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0
  };

  vector<float> a_2 = {
    0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 1.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0
  };

  vector<float> a_3 = {
    0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.1, 0.1, 0.1, 0.0,
    0.0, 0.1, 1.0, 0.1, 0.0,
    0.0, 0.1, 0.1, 0.1, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0
  };

  vector<float> dat;

  ifstream inputFile("pixels.dat");

  if (inputFile) {
    float next;
    while (inputFile >> next) dat.push_back(next);
  }

  int its = 2;
  //TODO: Allow reading from a file for larger matrices.
  Relax *r = new Relax(dat, r_2);
  int l = 0;
  int dps = 4;
  int n = r->get_n();
  vector<float> p_new;

  for (int it = 1; it <= its; ++it) {
    p_new = {};
    cout << "ITERATION " << it << ":" << endl;
    cout << "---------------------------------------" << endl;
    for (int i = 0; i < n; ++i) {
      float next = r->p_next(i, l);
      p_new.push_back(next);
      cout << setprecision(dps) << next << "\t";
      if ((i + 1) % 5 == 0) cout << endl;
    }
    r = new Relax(p_new, r_2);
  }
  //TODO: Is this a memory leak?
  delete r;
}
