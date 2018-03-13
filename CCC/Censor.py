total = int(raw_input())

for i in range(total):
  sentence = raw_input()
  sentence = sentence.split()
  for i in range(len(sentence)):
    if len(sentence[i]) == 4:
      sentence[i] = "****"
  print " ".join(sentence)
