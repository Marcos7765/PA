PROGRAMA1=$1
PROGRAMA2=$2
MAX_TENTATIVAS=5
ITENS=25
MAX_ITENS=3200
CRESC_ITENS=2

echo ITENS, MIN $PROGRAMA1, MIN $PROGRAMA2, MEDIA $PROGRAMA1, MEDIA $PROGRAMA2

while [ "$ITENS" -le "$MAX_ITENS" ]
do

    TENTATIVA=1
    RECORDE1=-1
    RECORDE2=-1
    TOTAL1=0
    TOTAL2=0

    while [ "$TENTATIVA" -le "$MAX_TENTATIVAS" ]
    do

        VETOR=""
        for i in `seq $ITENS`
        do
            VETOR="$VETOR $RANDOM"
        done

        TEMPO=`$PROGRAMA1 $VETOR`
        if [ `python3 -c "print(($TEMPO < $RECORDE1) or ($RECORDE1 < 0))"` = "True" ]
        then
            RECORDE1=$TEMPO
        fi
        TOTAL1=`python3 -c "print(($TOTAL1 + $TEMPO))"`

        TEMPO=`$PROGRAMA2 $VETOR`
        if [ `python3 -c "print(($TEMPO < $RECORDE2) or ($RECORDE2 < 0))"` = "True" ]
        then
            RECORDE2=$TEMPO
        fi
        TOTAL2=`python3 -c "print(($TOTAL2 + $TEMPO))"`

        TENTATIVA=$((TENTATIVA+1))
    done

    echo $ITENS, $RECORDE1, $RECORDE2, `python3 -c "print(f'{($TOTAL1 / $MAX_TENTATIVAS):.3e}')"`\
    , `python3 -c "print(f'{($TOTAL2 / $MAX_TENTATIVAS):.3e}')"`

    ITENS=$((ITENS*CRESC_ITENS))
done
echo Fim do programa