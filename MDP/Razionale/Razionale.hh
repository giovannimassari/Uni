#pragma once

namespace Numerica {

class Razionale {
public:
  
  Razionale() = default;

  Razionale(int num, int den);

  // per copia       
  Razionale(const Razionale& y) = default;
  Razionale& operator=(const Razionale& y) = default;
	

  // per spostamento
  Razionale(Razionale&& y) = default;
  Razionale& operator=(Razionale&& y) = default;
	
  // distruttore
  ~Razionale() = default;

  Razionale operator+(const Razionale& y) const;
  Razionale operator-(const Razionale& y) const;
  Razionale operator*(const Razionale& y) const;
  Razionale operator/(const Razionale& y) const;

  Razionale& operator+();
  Razionale& operator-();
  
  Razionale& operator+=(const Razionale& y);
  Razionale& operator-=(const Razionale& y);
  Razionale& operator*=(const Razionale& y);
  Razionale& operator/=(const Razionale& y);

  
  Razionale& operator++();
  Razionale& operator--();


  bool operator==(const Razionale& y) const;
  bool operator>(const Razionale& y) const;
  bool operator<(const Razionale& y) const;
  bool operator<=(const Razionale& y) const;
  bool operator>=(const Razionale& y) const;
  

private:

  int num;
  int den;
};


  std::ostream& operator<<(std::ostream& os) const;
  
  
} // namespace Numerica
