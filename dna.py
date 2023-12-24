import sys
import csv

def get_highest_substring(s, sub):
    ans = [0] * len(s)
    for i in range(len(s) - len(sub), -1, -1):
        if s[i: i + len(sub)] == sub:
            if i + len(sub) > len(s) - 1:
                ans[i] = 1
            else:
                ans[i] = 1 + ans[i + len(sub)]
    return max(ans)

def print_found(reader, authentic):
    for line in reader:
        person = line[0]
        values = [int(val) for val in line[1:]]
        if values == authentic:
            print(person)
            return
    print("No match")
    
def main():
    if len(sys.argv) != 3:
        print("Usage: python dna.py data.csv sequence.txt")
        sys.exit(1)

    get_csv = sys.argv[1]
    with open(get_csv) as csv_file:
        reader = csv.reader(csv_file)
        every_sequence = next(reader)[1:]
        
        get_text = sys.argv[2]
        with open(get_text) as text_file:
            s = text_file.read()
            authentic = [get_highest_substring(s, seq) for seq in every_sequence]

        print_found(reader, authentic)
            





if __name__=="__main__":
    main()