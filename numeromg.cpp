#include<iostream>
#include<string>

using namespace std;

string digits = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";

string toBase36(long long int number) {
  string val = number == 0 ? "0" : "";
  int mod = 0;

  while (number != 0) {
    mod = number % 36;
    val = digits[mod] + val;
    number /= 36;
  }

  return val;
}

long long int toInt(string number) {
  int n = number.length();
  long long int value = 0;
  int factor = 1;

  while (n--) {
    char letter = number[n];
    value += digits.find(letter) * factor;
    factor *= 36;
  }

  return value;
}

int main() {
  while (1) {
    string a, b;
    cin >> a >> b;

    if (a == "0" && b == "0") break;

    long long int sum = toInt(a) + toInt(b);
    printf("%s\n", toBase36(sum).c_str());
  }

  return 0;
}

