#!/bin/bash

img_dir="./captures"

destination=$1
timestamp=$2

img_path=${img_dir}/${timestamp}.jpg

body="La puerta de tu casa acaba de ser abierta. Mira quién la ha abierto en el archivo adjunto"
subject="Puerta_abierta"

echo $body |  mutt -s $subject $destination -a ${img_path}
rc=$? 

rm ${img_path}

exit $rc