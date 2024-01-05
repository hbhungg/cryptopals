from collections import Counter
import string

cipher_text = "1b37373331363f78151b7f2b783431333d78397828372d363c78373e783a393b3736"
b = bytes.fromhex(cipher_text)

def decrypt(cipher, key):
  return "".join([chr(x^key) for x in cipher])

def score(text):
  lower_text = text.lower()
  counter = Counter(lower_text)
  sorted_freq = sorted(counter, key=counter.get, reverse=True)

  # Descending letter frequency
  alphabet_freq = "etaoin shrdlu"
  s = 0

  for idx, c in enumerate(sorted_freq):
    # If include unprintable string, give it a very high score
    if c not in string.printable:
      return 1000 
    # Find the index of the character in the freq table
    true_freq = alphabet_freq.find(c) 
    # Get the distance between the text frequency and the alphabet frequency
    # If character not in freq, give it the highest score 13
    s += idx - true_freq if true_freq != -1 else 13
  return s 

# Brute force
possible = {(text:=decrypt(b, k), k): score(text) for k in range(255)}
sval = sorted(possible, key=possible.get)
val = sval[0]
decrypt_text, key = val[0], val[1]

print("Cipher text in hex:", cipher_text)
print("Decrypted text:", decrypt_text)
print("Key:", key)

