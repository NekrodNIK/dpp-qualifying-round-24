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


void setup() {
  Serial.begin(9600);
  int p = 13;
  int q = 47;
  int s, k, d;

  gen_keys(p, q, &s, &k, &d);

  int M = 10;
  int encoded = M^k % s;
  Serial.println(encoded);
  
  int decoded = encoded^d % s;

  if (M == decoded) {
    Serial.print("M == encoded -> successfully encode");
  }
}

void loop() {}
