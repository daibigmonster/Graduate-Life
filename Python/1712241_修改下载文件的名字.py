import os
import re
filenames = os.listdir()
for filename in filenames:
    oldname = filename
    newname = re.sub('[.*?]','',filename)
    os.rename = (oldname,newname)