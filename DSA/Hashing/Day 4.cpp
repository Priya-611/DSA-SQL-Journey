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


// Rules for choosing prime value
/*
1. prime < size         
      [ prime number must be smaller than the table size ]
      Ex: if size =10 , a good prime number is 7 (since 7<10)

2. it should be an actual prime number

3. 'prime' should be "relatively prime" to the 'size'     
      [ the GCD of prime and size must be 1 (means they don't share any common factor except 1) ]
      If h2(key) is not relatively prime to size, you might never probe all slots in the table — some slots will never be visited, leading to infinite loops or missed insertions.
      If your table size is prime itself (e.g., 11), you can just choose prime = size - 1.

*/


//Why to use Double Hashing
/*
1. Avoids Clustering (Better Distribution)
    Linear probing causes primary clustering — elements group together in long blocks.
    Quadratic probing reduces this a bit but still has secondary clustering.
    Double hashing uses a second hash function to "jump" in a custom way, greatly reducing clustering.

2. More Uniform Probing
    Double hashing spreads elements more uniformly across the table than linear/quadratic probing.

3. Better Performance under High Load Factor
    As the table fills, linear/quadratic probing take longer to find free spots.
    Double hashing still performs well because its probing path is more diverse.

| You’re trying to open a series of locked doors (slots):                             |
| ----------------------------------------------------------------------------------- |
| **Linear probing** walks door-to-door. 🏃‍♀️ (1 step at a time)                     |
| **Quadratic probing** hops in a fixed pattern. 🐇 (1², 2²...)                       |
| **Double hashing** teleports using a secret formula. 🔐 (random jumps based on key) |

*/











