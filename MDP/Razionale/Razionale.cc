#include <iostream>
#include "Razionale.hh"

namespace Numerica {

Razionale::Razionale(){
  this->num = 1;
  this->den = 1;
}

Razionale::Razionale(int num, int den){
  this->num = num;
  this->den = den;
}

// per copia
// Razionale(const Razionale& y) = default;
// Razionale& operator=(const Razionale& y) = default;


// per spostamento                                                              // Razionale(Razionale&& y) = default;
// Razionale& operator=(Razionale&& y) = default;

// distruttore di default
    
  
  
Razionale Razionale::operator+(const Razionale& y) const {
  return Razionale(this->num * y.den + this->den * y.num, this->den * y.den);
}

Razionale Razionale::operator-(const Razionale& y) const {
  return Razionale(this->num * y.den - this->den * y.num, this->den * y.den);
}

Razionale Razionale::operator*(const Razionale& y) const {
  return Razionale(this->num * y.num, this->den * y.den);
}

Razionale Razionale::operator/(const Razionale& y) const {	
  return Razionale(*this * (Razionale(y.den, y.num)));
}


  


Razionale& Razionale::operator+() {
  return *this;
}

Razionale& Razionale::operator-() {
  this->num = -this->num;
  return *this;
}

  



  Razionale& Razionale::operator+=(const Razionale& y) {
  this->num = this->num * y.den + this->den * y.den;
  this->den = this->den * y.den;
  return *this;
}

Razionale& Razionale::operator-=(const Razionale& y) {
  *this += -y;
  return *this;
}

Razionale& Razionale::operator*=(const Razionale& y) {
  this->num *= y.num;
  this->den *= y.den;
  return *this;
}
    
Razionale& Razionale::operator/=(const Razionale& y) {
  this->num /= y.num;
  this->den /= y.den;
  return *this;
}
  


  

Razionale& Razionale::operator++() {
  *this += Razionale();
  return *this;
}
  
Razionale& Razionale::operator--() {
  *this -= Razionale();
  return *this;
}
  


bool Razionale::operator==(const Razionale& y) const {
  if(*this == y) return true;
  return this->num == y.num && this->den == y.den;
}
  
bool Razionale::operator>(const Razionale& y) const {
  if(*this == y) return false;
  if(this->num == y.num && this->den == y.den) return	false;
  return this->num * y.den > y.num * this->den;
}
			      
bool Razionale::operator<(const Razionale& y) const {
  if(*this ==	y) return false;
  if(this->num == y.num && this->den == y.den) return false;
  return !(*this > y);
}

bool Razionale::operator>=(const Razionale& y) const {
  return !(*this < y);
}
  
bool Razionale::operator<=(const Razionale& y) const {
  return !(*this > y);
}

std::ostream& print(std::ostream& os) const {
  os << this->num << "/" << this->den << std::endl;
  return os;
}

std::ostream& operator<<(std::ostream& os) const {
  return this.print(os);
}

  
} // namespace Numerica
