import base64

input = "49276d206b696c6c696e6720796f757220627261696e206c696b65206120706f69736f6e6f7573206d757368726f6f6d"
result = "SSdtIGtpbGxpbmcgeW91ciBicmFpbiBsaWtlIGEgcG9pc29ub3VzIG11c2hyb29t"

def bin2base64(val):
  if 0<=val<=25: return chr(val+ord("A"))
  elif 26<=val<=51: return chr(val-26+ord("a"))
  elif 52<=val<=61: return chr(val-52+ord("0"))
  elif val == 62: return "+"
  elif val == 63: return "/"
  else: return "?"


val = ""
for i in range(0, len(input), 3):
  chunk = int(input[i:i+3], 16)
  print(chunk, bin(chunk))
  b1, b2 = chunk >> 6, (chunk & (1 << 6)-1)
  val += bin2base64(b1)
  val += bin2base64(b2)

print(val)
