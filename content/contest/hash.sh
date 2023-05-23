# Hashes a file, ignoring all whitespace and comments. Use for
# verifying that code was correctly typed.
# Usage: ./hash.sh < FILE (make executable first: chmod +x hash.sh)
# cpp -dD -P -fpreprocessed | tr -d '[:space:]'| md5sum |cut -c-6
cpp -dD -P -fpreprocessed | tr -d '[:space:]' | md5sum | awk '{print substr($1, 1, 6)}'