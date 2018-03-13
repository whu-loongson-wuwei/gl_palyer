import os
file = open("args.desc.txt",'r')
args_dict_write = {}
args_dict_read = {}
lines = file.readlines();
size = len(lines)
func_name_pre = 'begin_read'
args_dict_read[func_name_pre] = []
for index in xrange(size):
    line = lines[index]
    ind = line.find(r'//gl')
    if ind != -1:
        func_name = line[ind+2:line.find('\r')]
        if args_dict_write.has_key(func_name):
            args_dict_read[func_name] = []
            args_dict_read[func_name].append(index+1)
            args_dict_write[func_name].append(index)
            func_name_pre = func_name
        else:
            args_dict_write[func_name] = []
            args_dict_read[func_name_pre].append(index)
            args_dict_write[func_name].append(index+1)
print args_dict_write
print '\n\n'
print args_dict_read


