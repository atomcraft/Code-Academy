#!/bin/bash
case $2 in
     "+")
         echo $(($1 + $3))
     ;;

     "-")
         echo $(($1 - $3))
      ;;
 
      "*")
          echo $(($1 \* $3))
      ;;
 
      "/")
          echo `bc <<< "scale=2; $1/$3"`
      ;;
 
      *)
         echo "Incorect operation!"
      ;;
  esac
