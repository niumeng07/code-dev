cat words.txt | tr -s ' ' '\n'| sort | uniq -c | awk -F" " '{print $2, $1}' | sort -k2 -g -r
