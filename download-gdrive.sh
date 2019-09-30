#!/bin/bash
fileid="1ntx6Mpor-GWRl3CSiAQ47H8RQOKYeoWJ"
filename="riscv-gcc.tar.gz"
curl -c ./cookie -s -L "https://drive.google.com/uc?export=download&id=${fileid}" > /dev/null
curl -Lb ./cookie "https://drive.google.com/uc?export=download&confirm=`awk '/download/ {print $NF}' ./cookie`&id=${fileid}" -o ${filename}

