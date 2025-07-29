// Double Hashing
/*
Double Hashing is a collision resolution technique used in hash tables.
If a key maps to an already filled index (i.e., collision happens), we use a second hash function to compute the jump size (step).

In double hashing, we still start with a primary hash function, like division or mid-square — just like linear/quadratic probing.
👉 But we also define a second hash function (usually with division method and a prime number), like this:
h1(key) = key % size          // primary hash
h2(key) = prime - (key % prime)   // secondary hash  [it helps avoid common multiples and ensures we check different spots instead of clustering (like in linear or quadratic).]

And probing becomes:
(h1 + i * h2(key)) % size



EX:
Let’s say:
size = 10
prime = 7
First formula (h1) = key % size → finds the first slot
Second formula (h2) = prime - (key % prime) → tells how far to jump if there's a collision

Let’s insert the key 27 into the hash table.
  First hash:
  h1 = 27 % 10 = 7
  → Try to put 27 at index 7.
  
  Suppose index 7 is already full, now do second hash:
  h2 = 7 - (27 % 7) = 7 - 6 = 1
  So we jump 1 step each time.

  Try next slots:    (h1 + i * h2(key)) % size
  i = 1: (7 + 1 * 1) % 10 = 8
  i = 2: (7 + 2 * 1) % 10 = 9
  i = 3: (7 + 3 * 1) % 10 = 0
...
Keep trying until you find an empty slot.





*/
