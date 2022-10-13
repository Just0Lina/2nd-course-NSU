#ifndef BIGINT_H_
#define BIGINT_H_
#include <sstream>
#include <vector>

// #include <fstream>
#include <iostream>

class BigInt {
 public:
  BigInt() = default;
  BigInt(const int);             //++
  explicit BigInt(std::string);  //++
  BigInt(const BigInt&);         //++
  BigInt(BigInt&&);              //++
  int comparasion(std::string other);
  ~BigInt() = default;
  BigInt get_ones_comp() const;
  BigInt get_from_ones_comp() const;
  BigInt& get_bin_var(int size);
  void fix_variable_look(bool all_zero);

  bool empty();                             //++
  BigInt& operator=(const BigInt&);         //++
  BigInt& operator=(BigInt&&);              //++
  bool operator[](size_t pos);              //++
  const bool operator[](size_t pos) const;  //++

  BigInt operator~() const;  //++

  BigInt& operator++();          //++
  const BigInt operator++(int);  //+
  BigInt& operator--();          //++
  const BigInt operator--(int);  //++

  BigInt& operator+=(const BigInt&);  //++
  BigInt& operator-=(const BigInt&);  //++
  BigInt& operator*=(const BigInt&);
  BigInt& operator/=(const BigInt&);
  BigInt& operator%=(const BigInt&);
  BigInt& operator^=(const BigInt&);  //+
  BigInt& operator&=(const BigInt&);  //+
  BigInt& operator|=(const BigInt&);  //+

  BigInt operator+() const;  // unary +
  BigInt operator-() const;  // unary -

  bool operator==(const BigInt& other) const;  //++
  bool operator!=(const BigInt& other) const;  //++
  bool operator<(const BigInt& other) const;   //++
  bool operator>(const BigInt& other) const;   //++
  bool operator<=(const BigInt& other) const;  //++
  bool operator>=(const BigInt& other) const;  //++

  std::string get_number() const;

  void mini_inc(std::vector<bool>& big_int_);
  void mini_dec(std::vector<bool>& big_int_);
  void minisum(const BigInt& other);
  void minisub(const BigInt& other);
  bool is_less(const BigInt& other) const;

  std::pair<BigInt, BigInt> get_quotient_reminder(const BigInt& other);

  operator int() const;
  operator std::string() const;

  size_t size() const;  // size in bytes
  bool sign();

 private:
  bool sign_ = true;
  std::vector<bool> big_int_;
};

BigInt operator+(const BigInt&, const BigInt&);
BigInt operator-(const BigInt&, const BigInt&);
BigInt operator*(const BigInt&, const BigInt&);
BigInt operator/(const BigInt&, const BigInt&);
BigInt operator^(const BigInt&, const BigInt&);
BigInt operator%(const BigInt&, const BigInt&);
BigInt operator&(const BigInt&, const BigInt&);
BigInt operator|(const BigInt&, const BigInt&);

std::ostream& operator<<(std::ostream& o, const BigInt& i);

#endif
