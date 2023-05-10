st=0
ed=0
if [ ${FT_LINE1} -lt ${FT_LINE2} ]; then
	st=${FT_LINE1}
	ed=${FT_LINE2} 
else
	st=${FT_LINE2}
	ed=${FT_LINE1}
fi
cat /etc/passwd | grep -v '^#' | awk 'NR%2==0 {print $0}' | sed 's/:.*//' | rev | sort -r | awk 'NR>=st&&NR<=ed{print $0}' st=${st} ed=${ed} | tr '\n' ',' | sed 's/,/, /g' | sed 's/..$/./' | tr -d '\n'
