words = input("Enter string: ").split()

long = max(words, key=len)
short = min(words, key=len)

print(f"the longest word is \"{long}\" ({len(long)} characters)")
print(f"the shortest word is \"{short}\" ({len(short)} characters)")