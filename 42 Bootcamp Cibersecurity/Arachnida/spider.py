# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    spider.py                                          :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: amayo-ca <amayo-ca@student.42barc...>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/03 17:01:45 by amayo-ca          #+#    #+#              #
#    Updated: 2022/08/29 16:59:24 by amayo-ca         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

import requests
from bs4 import BeautifulSoup
import os
from tld import get_fld
import argparse
import urllib.request
import string
import random
import colorama
from colorama import Fore


def banner():

	bcn ='''42Barcelona'''
	
	banner_tool = ''' _____ ____  ____  ___      ___  ____  
 / ___/|    \l    j|   \    /  _]|    \ 
(   \_ |  o  )|  T |    \  /  [_ |  D  )
 \__  T|   _/ |  | |  D  YY    _]|    / 
 /  \ ||  |   |  | |     ||   [_ |    \ 
 \    ||  |   j  l |     ||     T|  .  Y
  \___jl__j  |____jl_____jl_____jl__j\_j'''
	by ='''                                 by M4Y0  '''
	print("")
	print(Fore.MAGENTA + bcn)
	print(Fore.GREEN + banner_tool)
	print(Fore.CYAN + by)
	print(Fore.RESET)

extensions = ['.jpg', '.jpeg', '.png', '.gif', '.bmp']
directory = "data/"


def main(url, domain, recursive, defsublevel):

	sublevel = 0

	if recursive == "False":
		sublevel = 4
	
	if not os.path.exists(directory):
		os.mkdir(directory)

	takeimg(url, domain, sublevel, defsublevel)


def takeimg(url, domain, sublevel, defsublevel):

	listimg = []
	listlink = []
	print(sublevel)
	r = requests.get(url)
	html = r.content
	soup = BeautifulSoup(html, "html.parser")
	imgcontent = soup.find_all('img')
	linkcontent = soup.find_all('a')

	if sublevel < defsublevel:

		sublevel = sublevel + 1

		for element in imgcontent:
			listimg.append(element['src'])

		for element in listimg:
			file_name, file_ext = os.path.splitext(element)

			if file_ext in extensions:
				print(element)
				download(element)

		for element in linkcontent:

			if element['href'] == "":
				continue
			link_domain = get_fld(element['href'])

			if link_domain == domain:
				listlink.append(element['href'])
				takeimg(element['href'], domain, sublevel, defsublevel)

		print(listlink)

	else:
		exit()


def download(element):

	imgcontent = requests.get(element).content
	file_name, file_ext = os.path.splitext(element)
	rand = ''.join(random.choices(string.ascii_uppercase + string.digits, k=5))
	name = rand + file_ext
	f = open(directory + name, "wb")
	f.write(imgcontent)


if __name__ == '__main__':

	parser = argparse.ArgumentParser()

	parser.add_argument('-r', action = 'store_true', help='./spider -r [URL] ')
	parser.add_argument('-l', type = int, help='./spider -r -l<number> [URL] ')
	parser.add_argument('-p', type = str, help = './spider -p [PATH] [URL]', required = False)
	parser.add_argument('url', type = str, action = 'store', help = '<required> link to the website.')

	args = parser.parse_args()
	print("hey:  ", args.l)
	print(args)
	print(parser)

	if args.url:
		url = str(args.url)
		print(url)
		if args.r:
			recursive = "True"
			if args.l:
				defsublevel = args.l
			elif args.l == None:
				defsublevel = 5
		else:
			recursive = "False"
			defsublevel = 5
		
		if args.p:
			directory = str(args.p)
			defsublevel = 5
	else:
		print("Falta la url wacho")

	# url = 'https://www.42barcelona.com/es'
	domain = get_fld(url)
	print(domain)
	banner()
	main(url, domain, recursive, defsublevel)
