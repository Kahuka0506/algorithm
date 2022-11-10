import os
import datetime

files = os.listdir("./")

for f in files:
    path = os.path.join("./", f)
    if os.path.isfile(path):
        print("file   :", f, " ", os.path.splitext(f)[1], "  ", datetime.datetime.fromtimestamp(os.path.getmtime(path)))
        if(os.path.splitext(f)[1] == ".md"):
            os.remove(path)
        #root_ext_pair = os.path.splitext(f)
        #print(root_ext_pair[1])
    if os.path.isdir(path):
        print("folder :", f)
        

print("-"*50)



output_file = open('../README.md','w')
output_file.write("""
<h2 align="center">Algorithm Library</h2>
<p align="center"> </p>

[![Kahuka](https://img.shields.io/endpoint?url=https%3A%2F%2Fatcoder-badges.now.sh%2Fapi%2Fatcoder%2Fjson%2FKahuka)](https://atcoder.jp/users/Kahuka)
[![Kahuka](https://img.shields.io/endpoint?url=https%3A%2F%2Fatcoder-badges.now.sh%2Fapi%2Fcodeforces%2Fjson%2FKahuka)](https://codeforces.com/profile/Kahuka)

    
        
[List](./doc/index.md)

""")

files = os.listdir("../")
for f in files:
    path = os.path.join("../", f)
    if os.path.isdir(path):
        #output_file.write('### [' + os.path.splitext(f)[0] + '](./' + path + ')\n')
                
        files_d = os.listdir(path)
        for f_d in files_d:
            path_d = os.path.join(path, f_d)
            if os.path.isfile(path_d):
                if(os.path.splitext(f_d)[0] == "README"):
                    #output_file.write('- [' + os.path.splitext(f_d)[0] + '](./' + os.path.splitext(f_d)[0] + '.md' + ')\n')
                    top = 0
                    with open(path_d, 'r') as data:
                        for text in data.readlines():
                            output_file.write(text)
                            if(top==0):
                                output_file.write('[' + os.path.splitext(f)[0] + "/" + f_d +'](./' + f +"/" + f_d + ')\n')
                                top=1
                    output_file.write("\n\n")

output_file.close()
        






files = os.listdir("../")

output_file = open('index.md','w')
output_file.write("# Algorithm\n")
for f in files:
    path = os.path.join("../", f)
    if os.path.isdir(path):
        output_file.write('### [' + os.path.splitext(f)[0] + '](./' + path + ')\n')
                
        files_d = os.listdir(path)
        for f_d in files_d:
            path_d = os.path.join(path, f_d)
            if os.path.isfile(path_d):
                if(os.path.splitext(f_d)[1] == ".cpp"):
                    output_file.write('- [' + os.path.splitext(f_d)[0] + '](./' + os.path.splitext(f_d)[0] + '.md' + ')\n')

                    md_file = open(os.path.splitext(f_d)[0] + '.md','w')
                    md_file.write("# " + os.path.splitext(f_d)[0] + "\n")
                    
                    md_file.write("リンク : [" + path_d + "](" + path_d + ")" + "    \n")
                    md_file.write("最終更新 : " + str(datetime.datetime.fromtimestamp(os.path.getmtime(path_d))) + "\n")
                    
                    #md_file.write("## about\n")

                    #md_file.write("## src\n"")
                    md_file.write("\n" + "```cpp\n")
                    with open(path_d, 'r') as data:
                        md_file.write(data.read())
                    md_file.write("```")
                    md_file.close()

output_file.close()
        

