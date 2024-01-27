#define int int32_t

int gcd(int a, int b) {
    while (a != 0 and b != 0) {
        if (a > b) {
            a = a % b;
        } else {
            b = b % a;
        }
    }

    return max(a, b);
}


void gen_keys(int p, int q, int* Is, int* Ik, int* Id) {
    int s = p * q;
    int F = (p-1)*(q-1);
    
    int k = F;
    for (;gcd(F, k) > 1; k--) {}

    int d = 1;
    for (;(d*k) % F != 1; d++) {}

    *Is = s;
    *Ik = k;
    *Id = d;
}

int rsa_encode(int value, int s, int k) {
  return value^k % s;
}

int rsa_decode(int value, int s, int d) {
  return value^d % s;
}

void setup() {
  Serial.begin(9600);
  int p = 13;
  int q = 47;
  int s, k, d;

  gen_keys(p, q, &s, &k, &d);

  int M = 10;
  int encoded = rsa_encode(M, s, k);
  Serial.println(encoded);
  
  int decoded = rsa_decode(encoded, s, k);

  if (M == decoded) {
    Serial.print("M == encoded -> successfully encode");
  }
}

void loop() {}
