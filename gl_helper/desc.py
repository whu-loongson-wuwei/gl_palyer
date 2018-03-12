for ind in len(ps):
	p = ps[ind].split()
	if p[-1].find('*') == 0 :
	    stmt_d_1 = self.indent
	    stmt_d_1 += 'size = sizeof({})'.format(p[-1])
	    stmt_d_2 = self.indent
	    stmt_d_2 += 'p_depth = 0'
	    stmt_d_3 = self.indent
	    stmt_d_3 = 'fwrite(dp,1,size,&{})'.format(p[-1])
	elif ' '.join(p[-1]).find('*') == 0:
	    stmt_d_1 = self.indent
	    if 
	    stmt_d_1 += 'size = sizeof({})'.format(p[-1])

