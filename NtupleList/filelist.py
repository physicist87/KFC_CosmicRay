import os
import sys
import subprocess
import argparse
print (os.getcwd())
#cur_dir ="/storage/palgongsan/sha/Analysis/KFC_DREAM/Cosmiclay/Analysis/Ntuples/v2p3"
parser = argparse.ArgumentParser(description = 'options for Ntuple List')

parser.add_argument('--SelectFiles',dest="isSelected",action="store", default="false",nargs='+',help='Write ntuple files you want to list. By default, all files in the Ntuple Directory are included.')
parser.add_argument('--UsedCap',dest="isdcap",action="store",default= "False",help='Please indicate whether you would like to use dcap by setting it to True. If you do not wish to use dcap, please select False.')
parser.add_argument('--ListDirName',dest="Listdir",action="store",default= "InputList",help='Please enter the name of the directory where you want to save the list of files. By default, the directory name is InputList.')
parser.add_argument('--NtupleDirName',dest="Ntupledir",action="store",default= "/pnfs/knu.ac.kr/data/cms/store/user/sha/KFC_project/CosmicRay_Nutples/v2p4",help='Please enter the name of the Ntuple directory. By default, the directory name is /pnfs/knu.ac.kr/data/cms/store/user/sha/KFC_project/CosmicRay_Nutples/v2p4')
args = parser.parse_args()



def main():
    ### make Input files list directory ###
    cur_dir =os.getcwd()
    print (args.Listdir)
    os.system("mkdir -p %s/%s"%(cur_dir,args.Listdir))
    ### Set Ntuple Dir ###
    #ntupleDir = "/pnfs/knu.ac.kr/data/cms/store/user/sha/KFC_project/CosmicRay_Nutples/v2p4"
    ntupleDir = args.Ntupledir #"/pnfs/knu.ac.kr/data/cms/store/user/sha/KFC_project/CosmicRay_Nutples/v2p4"
    print (args.isSelected)
    if(args.isSelected == "false"):
        print ('good')
        ### Load Rootfiles ###
        file_list = os.listdir(ntupleDir)
        print(file_list)
        for ifile in file_list:
            #print(ifile)
            ifname = ifile.replace(".root",".list")
            print("%s -> %s"%(ifile,ifname))
            listfile = open("%s/%s/input_%s"%(cur_dir,args.Listdir,ifname),"w")
            if(args.isdcap == "True"):
                print("do dcap option")
                listfile.write("dcap://cluster142.knu.ac.kr/%s/%s\n"%(ntupleDir,ifile))
            else :
                print("do not dcap option!")
                listfile.write("%s/%s\n"%(ntupleDir,ifile))
            listfile.close()
            pass
    else :
        print("do selected files!!")
        print(args.isSelected)
        for ifile in args.isSelected:
            if (os.path.isfile("%s/%s"%(ntupleDir,ifile)) == "True"): 
                ifname = ifile.replace(".root",".list")
                print("%s -> %s"%(ifile,ifname))
                listfile = open("%s/%s/input_%s"%(cur_dir,args.Listdir,ifname),"w")
                #listfile.write("dcap://cluster142.knu.ac.kr/%s/%s\n"%(ntupleDir,ifile))
                if(args.isdcap == "True"):
                    print("do dcap option")
                    listfile.write("dcap://cluster142.knu.ac.kr/%s/%s\n"%(ntupleDir,ifile))
                else : 
                    print("do not dcap option!")
                    listfile.write("%s/%s\n"%(ntupleDir,ifile))
                listfile.close()
                pass
            else : print("check out files %s/%s",ntupleDir,ifile)
            pass
        pass 
    pass 
#for idx in range(5659,5697+1):
"""
for idx in range(5659,5698+1):
    print("index : %s",idx)
    ntfile =""
    isfile = False
    cmd = ""
    if os.path.isfile(cur_dir +"/v1_output_Run%s_MID7.root"%(idx)):
        ntfile = cur_dir +"/v1_output_Run%s_MID7.root"%(idx)
        print("current file %s",ntfile)
        cmd = "ls %s > input_Run%s_MID7.list"%(ntfile,idx)
    elif os.path.isfile(cur_dir +"/v1_output_Run%s_MID11.root"%(idx)):
        ntfile = cur_dir +"/v1_output_Run%s_MID11.root"%(idx)
        print("current file %s",ntfile)
        cmd = "ls %s > input_Run%s_MID11.list"%(ntfile,idx)
    else :
        print("no file !! %s", ntfile)
        cmd = "ls -al v1_*_Run%s_*.root"%(idx)
        #continue
    print(cmd)
    os.system(cmd)

"""
if __name__ == "__main__":
    main()
