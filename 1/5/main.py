from itertools import cycle

inp = """Burning 'em, if you ain't quick and nimble
I go crazy when I hear a cymbal"""
result = "0b3637272a2b2e63622c2e69692a23693a2a3c6324202d623d63343c2a26226324272765272a282b2f20430a652e2c652a3124333a653e2b2027630c692b20283165286326302e27282f"

def encrypt(plain_text, key):
  plain_text_bytes = inp.encode("utf-8")
  key_bytes = key.encode("utf-8")
  zip_list = zip(plain_text_bytes, cycle(key_bytes))
  retval = ""
  for c, k in zip_list:
    xorv = c^k
    retval += f"{xorv:02x}"
  return retval

retval = encrypt(inp, "ICE")
print(retval)
assert retval == result
