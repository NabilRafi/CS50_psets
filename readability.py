import cs50

Text = cs50.get_string("Text: ").strip()
count_letters, count_words, count_sentences = 0, 0, 0   
    
for i in range(len(Text)):
    if (i == 0 and Text[i] != ' ') or (i != len(Text) - 1 and Text[i] == ' ' and Text[i + 1] != ' '):
        count_words += 1
    if Text[i].isalpha():
        count_letters += 1
    if Text[i] == '.' or Text[i] == '?' or Text[i] == '!':
        count_sentences += 1
        
L = (count_letters / count_words) * 100
S = (count_sentences / count_words) * 100
x = round(0.0588 * L - 0.296 * S - 15.8)
   
if x >= 16:
    print("Grade 16+")
elif x <= 1:
    print("Before Grade 1")
else:
    print(f"Grade {x}")
        
