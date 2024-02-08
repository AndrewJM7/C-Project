EXAMPLE OF CLIENT LOG FOR SUCCESSFUL TRANSFER WITH TIMEOUT

++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
Running client as:
./rft_client in660.txt out/out.txt 127.0.0.1 20333 wt 0.5
++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

-------------------------------------------------------------------------------
CLIENT [rft_client.c:57:state:PS_INIT]
Initialised for wt transfer of file: in660.txt to file: out/out.txt
on server: 127.0.0.1:20333 with loss probality: 0.500000
-------------------------------------------------------------------------------
-------------------------------------------------------------------------------
CLIENT [rft_client.c:81:state:PS_TFR_READY]
Opened file: in660.txt (660 bytes), socket and server set.
Client ready for transfer
-------------------------------------------------------------------------------
-------------------------------------------------------------------------------
CLIENT [rft_client_util.c:244:state:PS_START_SEND]
Start sending file in wt mode
-------------------------------------------------------------------------------
-------------------------------------------------------------------------------
CLIENT [rft_client_util.c:256:state:PS_SEND_DATA]
Sending segment with sq: 0, file data: 35, checksum: 0
current retry: 0, max retries allowed: 20
payload:
We
all
use operating systems and ne
-------------------------------------------------------------------------------
-------------------------------------------------------------------------------
CLIENT [rft_client_util.c:274:state:PS_ACK_WAIT]
Waiting for an ACK
-------------------------------------------------------------------------------
-------------------------------------------------------------------------------
CLIENT [rft_client_util.c:285:state:PS_NO_ACK]
>>>> ACK timeout for segment with sq: 0 <<<<
-------------------------------------------------------------------------------
-------------------------------------------------------------------------------
CLIENT [rft_client_util.c:256:state:PS_RESEND_DATA]
Resending segment with sq: 0, file data: 35, checksum: -827602311
current retry: 1, max retries allowed: 20
payload:
We
all
use operating systems and ne
-------------------------------------------------------------------------------
-------------------------------------------------------------------------------
CLIENT [rft_client_util.c:274:state:PS_ACK_WAIT]
Waiting for an ACK
-------------------------------------------------------------------------------
-------------------------------------------------------------------------------
CLIENT [rft_client_util.c:285:state:PS_NO_ACK]
>>>> ACK timeout for segment with sq: 0 <<<<
-------------------------------------------------------------------------------
-------------------------------------------------------------------------------
CLIENT [rft_client_util.c:256:state:PS_RESEND_DATA]
Resending segment with sq: 0, file data: 35, checksum: -968757320
current retry: 2, max retries allowed: 20
payload:
We
all
use operating systems and ne
-------------------------------------------------------------------------------
-------------------------------------------------------------------------------
CLIENT [rft_client_util.c:274:state:PS_ACK_WAIT]
Waiting for an ACK
-------------------------------------------------------------------------------
-------------------------------------------------------------------------------
CLIENT [rft_client_util.c:300:state:PS_ACK_RECV]
ACK with sq: 0 received
-------------------------------------------------------------------------------
-------------------------------------------------------------------------------
CLIENT [rft_client_util.c:256:state:PS_SEND_DATA]
Sending segment with sq: 1, file data: 35, checksum: 3261
current retry: 0, max retries allowed: 20
payload:
tworks every day, when we use a mob
-------------------------------------------------------------------------------
-------------------------------------------------------------------------------
CLIENT [rft_client_util.c:274:state:PS_ACK_WAIT]
Waiting for an ACK
-------------------------------------------------------------------------------
-------------------------------------------------------------------------------
CLIENT [rft_client_util.c:285:state:PS_NO_ACK]
>>>> ACK timeout for segment with sq: 1 <<<<
-------------------------------------------------------------------------------
-------------------------------------------------------------------------------
CLIENT [rft_client_util.c:256:state:PS_RESEND_DATA]
Resending segment with sq: 1, file data: 35, checksum: -1948620018
current retry: 1, max retries allowed: 20
payload:
tworks every day, when we use a mob
-------------------------------------------------------------------------------
-------------------------------------------------------------------------------
CLIENT [rft_client_util.c:274:state:PS_ACK_WAIT]
Waiting for an ACK
-------------------------------------------------------------------------------
-------------------------------------------------------------------------------
CLIENT [rft_client_util.c:300:state:PS_ACK_RECV]
ACK with sq: 1 received
-------------------------------------------------------------------------------
-------------------------------------------------------------------------------
CLIENT [rft_client_util.c:256:state:PS_SEND_DATA]
Sending segment with sq: 2, file data: 35, checksum: 3225
current retry: 0, max retries allowed: 20
payload:
ile phone, tablet, laptop, or any n
-------------------------------------------------------------------------------
-------------------------------------------------------------------------------
CLIENT [rft_client_util.c:274:state:PS_ACK_WAIT]
Waiting for an ACK
-------------------------------------------------------------------------------
-------------------------------------------------------------------------------
CLIENT [rft_client_util.c:285:state:PS_NO_ACK]
>>>> ACK timeout for segment with sq: 2 <<<<
-------------------------------------------------------------------------------
-------------------------------------------------------------------------------
CLIENT [rft_client_util.c:256:state:PS_RESEND_DATA]
Resending segment with sq: 2, file data: 35, checksum: -1152299882
current retry: 1, max retries allowed: 20
payload:
ile phone, tablet, laptop, or any n
-------------------------------------------------------------------------------
-------------------------------------------------------------------------------
CLIENT [rft_client_util.c:274:state:PS_ACK_WAIT]
Waiting for an ACK
-------------------------------------------------------------------------------
-------------------------------------------------------------------------------
CLIENT [rft_client_util.c:285:state:PS_NO_ACK]
>>>> ACK timeout for segment with sq: 2 <<<<
-------------------------------------------------------------------------------
-------------------------------------------------------------------------------
CLIENT [rft_client_util.c:256:state:PS_RESEND_DATA]
Resending segment with sq: 2, file data: 35, checksum: -1623307499
current retry: 2, max retries allowed: 20
payload:
ile phone, tablet, laptop, or any n
-------------------------------------------------------------------------------
-------------------------------------------------------------------------------
CLIENT [rft_client_util.c:274:state:PS_ACK_WAIT]
Waiting for an ACK
-------------------------------------------------------------------------------
-------------------------------------------------------------------------------
CLIENT [rft_client_util.c:300:state:PS_ACK_RECV]
ACK with sq: 2 received
-------------------------------------------------------------------------------
-------------------------------------------------------------------------------
CLIENT [rft_client_util.c:256:state:PS_SEND_DATA]
Sending segment with sq: 3, file data: 35, checksum: 3131
current retry: 0, max retries allowed: 20
payload:
umber of other computing devices. A
-------------------------------------------------------------------------------
-------------------------------------------------------------------------------
CLIENT [rft_client_util.c:274:state:PS_ACK_WAIT]
Waiting for an ACK
-------------------------------------------------------------------------------
-------------------------------------------------------------------------------
CLIENT [rft_client_util.c:300:state:PS_ACK_RECV]
ACK with sq: 3 received
-------------------------------------------------------------------------------
-------------------------------------------------------------------------------
CLIENT [rft_client_util.c:256:state:PS_SEND_DATA]
Sending segment with sq: 4, file data: 35, checksum: 3290
current retry: 0, max retries allowed: 20
payload:
n ordinary user may not
be
interest
-------------------------------------------------------------------------------
-------------------------------------------------------------------------------
CLIENT [rft_client_util.c:274:state:PS_ACK_WAIT]
Waiting for an ACK
-------------------------------------------------------------------------------
-------------------------------------------------------------------------------
CLIENT [rft_client_util.c:300:state:PS_ACK_RECV]
ACK with sq: 4 received
-------------------------------------------------------------------------------
-------------------------------------------------------------------------------
CLIENT [rft_client_util.c:256:state:PS_SEND_DATA]
Sending segment with sq: 5, file data: 35, checksum: 3318
current retry: 0, max retries allowed: 20
payload:
ed in how the operating sy
stem of 
-------------------------------------------------------------------------------
-------------------------------------------------------------------------------
CLIENT [rft_client_util.c:274:state:PS_ACK_WAIT]
Waiting for an ACK
-------------------------------------------------------------------------------
-------------------------------------------------------------------------------
CLIENT [rft_client_util.c:300:state:PS_ACK_RECV]
ACK with sq: 5 received
-------------------------------------------------------------------------------
-------------------------------------------------------------------------------
CLIENT [rft_client_util.c:256:state:PS_SEND_DATA]
Sending segment with sq: 6, file data: 35, checksum: 3164
current retry: 0, max retries allowed: 20
payload:
a device they use works and may not
-------------------------------------------------------------------------------
-------------------------------------------------------------------------------
CLIENT [rft_client_util.c:274:state:PS_ACK_WAIT]
Waiting for an ACK
-------------------------------------------------------------------------------
-------------------------------------------------------------------------------
CLIENT [rft_client_util.c:300:state:PS_ACK_RECV]
ACK with sq: 6 received
-------------------------------------------------------------------------------
-------------------------------------------------------------------------------
CLIENT [rft_client_util.c:256:state:PS_SEND_DATA]
Sending segment with sq: 7, file data: 35, checksum: 3257
current retry: 0, max retries allowed: 20
payload:
 even know the operating system exi
-------------------------------------------------------------------------------
-------------------------------------------------------------------------------
CLIENT [rft_client_util.c:274:state:PS_ACK_WAIT]
Waiting for an ACK
-------------------------------------------------------------------------------
-------------------------------------------------------------------------------
CLIENT [rft_client_util.c:285:state:PS_NO_ACK]
>>>> ACK timeout for segment with sq: 7 <<<<
-------------------------------------------------------------------------------
-------------------------------------------------------------------------------
CLIENT [rft_client_util.c:256:state:PS_RESEND_DATA]
Resending segment with sq: 7, file data: 35, checksum: -619661390
current retry: 1, max retries allowed: 20
payload:
 even know the operating system exi
-------------------------------------------------------------------------------
-------------------------------------------------------------------------------
CLIENT [rft_client_util.c:274:state:PS_ACK_WAIT]
Waiting for an ACK
-------------------------------------------------------------------------------
-------------------------------------------------------------------------------
CLIENT [rft_client_util.c:300:state:PS_ACK_RECV]
ACK with sq: 7 received
-------------------------------------------------------------------------------
-------------------------------------------------------------------------------
CLIENT [rft_client_util.c:256:state:PS_SEND_DATA]
Sending segment with sq: 8, file data: 35, checksum: 3362
current retry: 0, max retries allowed: 20
payload:
sts.

	As computer scientists we bo
-------------------------------------------------------------------------------
-------------------------------------------------------------------------------
CLIENT [rft_client_util.c:274:state:PS_ACK_WAIT]
Waiting for an ACK
-------------------------------------------------------------------------------
-------------------------------------------------------------------------------
CLIENT [rft_client_util.c:300:state:PS_ACK_RECV]
ACK with sq: 8 received
-------------------------------------------------------------------------------
-------------------------------------------------------------------------------
CLIENT [rft_client_util.c:256:state:PS_SEND_DATA]
Sending segment with sq: 9, file data: 35, checksum: 3134
current retry: 0, max retries allowed: 20
payload:
th should be interested in how they
-------------------------------------------------------------------------------
-------------------------------------------------------------------------------
CLIENT [rft_client_util.c:274:state:PS_ACK_WAIT]
Waiting for an ACK
-------------------------------------------------------------------------------
-------------------------------------------------------------------------------
CLIENT [rft_client_util.c:285:state:PS_NO_ACK]
>>>> ACK timeout for segment with sq: 9 <<<<
-------------------------------------------------------------------------------
-------------------------------------------------------------------------------
CLIENT [rft_client_util.c:256:state:PS_RESEND_DATA]
Resending segment with sq: 9, file data: 35, checksum: -582758254
current retry: 1, max retries allowed: 20
payload:
th should be interested in how they
-------------------------------------------------------------------------------
-------------------------------------------------------------------------------
CLIENT [rft_client_util.c:274:state:PS_ACK_WAIT]
Waiting for an ACK
-------------------------------------------------------------------------------
-------------------------------------------------------------------------------
CLIENT [rft_client_util.c:300:state:PS_ACK_RECV]
ACK with sq: 9 received
-------------------------------------------------------------------------------
-------------------------------------------------------------------------------
CLIENT [rft_client_util.c:256:state:PS_SEND_DATA]
Sending segment with sq: 10, file data: 35, checksum: 3336
current retry: 0, max retries allowed: 20
payload:
 work and need to know how they wor
-------------------------------------------------------------------------------
-------------------------------------------------------------------------------
CLIENT [rft_client_util.c:274:state:PS_ACK_WAIT]
Waiting for an ACK
-------------------------------------------------------------------------------
-------------------------------------------------------------------------------
CLIENT [rft_client_util.c:300:state:PS_ACK_RECV]
ACK with sq: 10 received
-------------------------------------------------------------------------------
-------------------------------------------------------------------------------
CLIENT [rft_client_util.c:256:state:PS_SEND_DATA]
Sending segment with sq: 11, file data: 35, checksum: 3220
current retry: 0, max retries allowed: 20
payload:
k.

For example, it is not possible
-------------------------------------------------------------------------------
-------------------------------------------------------------------------------
CLIENT [rft_client_util.c:274:state:PS_ACK_WAIT]
Waiting for an ACK
-------------------------------------------------------------------------------
-------------------------------------------------------------------------------
CLIENT [rft_client_util.c:285:state:PS_NO_ACK]
>>>> ACK timeout for segment with sq: 11 <<<<
-------------------------------------------------------------------------------
-------------------------------------------------------------------------------
CLIENT [rft_client_util.c:256:state:PS_RESEND_DATA]
Resending segment with sq: 11, file data: 35, checksum: -164452082
current retry: 1, max retries allowed: 20
payload:
k.

For example, it is not possible
-------------------------------------------------------------------------------
-------------------------------------------------------------------------------
CLIENT [rft_client_util.c:274:state:PS_ACK_WAIT]
Waiting for an ACK
-------------------------------------------------------------------------------
-------------------------------------------------------------------------------
CLIENT [rft_client_util.c:285:state:PS_NO_ACK]
>>>> ACK timeout for segment with sq: 11 <<<<
-------------------------------------------------------------------------------
-------------------------------------------------------------------------------
CLIENT [rft_client_util.c:256:state:PS_RESEND_DATA]
Resending segment with sq: 11, file data: 35, checksum: -261603457
current retry: 2, max retries allowed: 20
payload:
k.

For example, it is not possible
-------------------------------------------------------------------------------
-------------------------------------------------------------------------------
CLIENT [rft_client_util.c:274:state:PS_ACK_WAIT]
Waiting for an ACK
-------------------------------------------------------------------------------
-------------------------------------------------------------------------------
CLIENT [rft_client_util.c:285:state:PS_NO_ACK]
>>>> ACK timeout for segment with sq: 11 <<<<
-------------------------------------------------------------------------------
-------------------------------------------------------------------------------
CLIENT [rft_client_util.c:256:state:PS_RESEND_DATA]
Resending segment with sq: 11, file data: 35, checksum: -224167013
current retry: 3, max retries allowed: 20
payload:
k.

For example, it is not possible
-------------------------------------------------------------------------------
-------------------------------------------------------------------------------
CLIENT [rft_client_util.c:274:state:PS_ACK_WAIT]
Waiting for an ACK
-------------------------------------------------------------------------------
-------------------------------------------------------------------------------
CLIENT [rft_client_util.c:285:state:PS_NO_ACK]
>>>> ACK timeout for segment with sq: 11 <<<<
-------------------------------------------------------------------------------
-------------------------------------------------------------------------------
CLIENT [rft_client_util.c:256:state:PS_RESEND_DATA]
Resending segment with sq: 11, file data: 35, checksum: -138900086
current retry: 4, max retries allowed: 20
payload:
k.

For example, it is not possible
-------------------------------------------------------------------------------
-------------------------------------------------------------------------------
CLIENT [rft_client_util.c:274:state:PS_ACK_WAIT]
Waiting for an ACK
-------------------------------------------------------------------------------
-------------------------------------------------------------------------------
CLIENT [rft_client_util.c:285:state:PS_NO_ACK]
>>>> ACK timeout for segment with sq: 11 <<<<
-------------------------------------------------------------------------------
-------------------------------------------------------------------------------
CLIENT [rft_client_util.c:256:state:PS_RESEND_DATA]
Resending segment with sq: 11, file data: 35, checksum: -183256744
current retry: 5, max retries allowed: 20
payload:
k.

For example, it is not possible
-------------------------------------------------------------------------------
-------------------------------------------------------------------------------
CLIENT [rft_client_util.c:274:state:PS_ACK_WAIT]
Waiting for an ACK
-------------------------------------------------------------------------------
-------------------------------------------------------------------------------
CLIENT [rft_client_util.c:285:state:PS_NO_ACK]
>>>> ACK timeout for segment with sq: 11 <<<<
-------------------------------------------------------------------------------
-------------------------------------------------------------------------------
CLIENT [rft_client_util.c:256:state:PS_RESEND_DATA]
Resending segment with sq: 11, file data: 35, checksum: -1649435914
current retry: 6, max retries allowed: 20
payload:
k.

For example, it is not possible
-------------------------------------------------------------------------------
-------------------------------------------------------------------------------
CLIENT [rft_client_util.c:274:state:PS_ACK_WAIT]
Waiting for an ACK
-------------------------------------------------------------------------------
-------------------------------------------------------------------------------
CLIENT [rft_client_util.c:285:state:PS_NO_ACK]
>>>> ACK timeout for segment with sq: 11 <<<<
-------------------------------------------------------------------------------
-------------------------------------------------------------------------------
CLIENT [rft_client_util.c:256:state:PS_RESEND_DATA]
Resending segment with sq: 11, file data: 35, checksum: -1742600889
current retry: 7, max retries allowed: 20
payload:
k.

For example, it is not possible
-------------------------------------------------------------------------------
-------------------------------------------------------------------------------
CLIENT [rft_client_util.c:274:state:PS_ACK_WAIT]
Waiting for an ACK
-------------------------------------------------------------------------------
-------------------------------------------------------------------------------
CLIENT [rft_client_util.c:285:state:PS_NO_ACK]
>>>> ACK timeout for segment with sq: 11 <<<<
-------------------------------------------------------------------------------
-------------------------------------------------------------------------------
CLIENT [rft_client_util.c:256:state:PS_RESEND_DATA]
Resending segment with sq: 11, file data: 35, checksum: -1192659059
current retry: 8, max retries allowed: 20
payload:
k.

For example, it is not possible
-------------------------------------------------------------------------------
-------------------------------------------------------------------------------
CLIENT [rft_client_util.c:274:state:PS_ACK_WAIT]
Waiting for an ACK
-------------------------------------------------------------------------------
-------------------------------------------------------------------------------
CLIENT [rft_client_util.c:285:state:PS_NO_ACK]
>>>> ACK timeout for segment with sq: 11 <<<<
-------------------------------------------------------------------------------
-------------------------------------------------------------------------------
CLIENT [rft_client_util.c:256:state:PS_RESEND_DATA]
Resending segment with sq: 11, file data: 35, checksum: -1352420793
current retry: 9, max retries allowed: 20
payload:
k.

For example, it is not possible
-------------------------------------------------------------------------------
-------------------------------------------------------------------------------
CLIENT [rft_client_util.c:274:state:PS_ACK_WAIT]
Waiting for an ACK
-------------------------------------------------------------------------------
-------------------------------------------------------------------------------
CLIENT [rft_client_util.c:300:state:PS_ACK_RECV]
ACK with sq: 11 received
-------------------------------------------------------------------------------
-------------------------------------------------------------------------------
CLIENT [rft_client_util.c:256:state:PS_SEND_DATA]
Sending segment with sq: 12, file data: 35, checksum: 3063
current retry: 0, max retries allowed: 20
payload:
 to detect and protect against cybe
-------------------------------------------------------------------------------
-------------------------------------------------------------------------------
CLIENT [rft_client_util.c:274:state:PS_ACK_WAIT]
Waiting for an ACK
-------------------------------------------------------------------------------
-------------------------------------------------------------------------------
CLIENT [rft_client_util.c:300:state:PS_ACK_RECV]
ACK with sq: 12 received
-------------------------------------------------------------------------------
-------------------------------------------------------------------------------
CLIENT [rft_client_util.c:256:state:PS_SEND_DATA]
Sending segment with sq: 13, file data: 35, checksum: 3290
current retry: 0, max retries allowed: 20
payload:
r attacks without an understanding 
-------------------------------------------------------------------------------
-------------------------------------------------------------------------------
CLIENT [rft_client_util.c:274:state:PS_ACK_WAIT]
Waiting for an ACK
-------------------------------------------------------------------------------
-------------------------------------------------------------------------------
CLIENT [rft_client_util.c:285:state:PS_NO_ACK]
>>>> ACK timeout for segment with sq: 13 <<<<
-------------------------------------------------------------------------------
-------------------------------------------------------------------------------
CLIENT [rft_client_util.c:256:state:PS_RESEND_DATA]
Resending segment with sq: 13, file data: 35, checksum: -269435969
current retry: 1, max retries allowed: 20
payload:
r attacks without an understanding 
-------------------------------------------------------------------------------
-------------------------------------------------------------------------------
CLIENT [rft_client_util.c:274:state:PS_ACK_WAIT]
Waiting for an ACK
-------------------------------------------------------------------------------
-------------------------------------------------------------------------------
CLIENT [rft_client_util.c:300:state:PS_ACK_RECV]
ACK with sq: 13 received
-------------------------------------------------------------------------------
-------------------------------------------------------------------------------
CLIENT [rft_client_util.c:256:state:PS_SEND_DATA]
Sending segment with sq: 14, file data: 35, checksum: 3414
current retry: 0, max retries allowed: 20
payload:
of operating systems and networks.

-------------------------------------------------------------------------------
-------------------------------------------------------------------------------
CLIENT [rft_client_util.c:274:state:PS_ACK_WAIT]
Waiting for an ACK
-------------------------------------------------------------------------------
-------------------------------------------------------------------------------
CLIENT [rft_client_util.c:285:state:PS_NO_ACK]
>>>> ACK timeout for segment with sq: 14 <<<<
-------------------------------------------------------------------------------
-------------------------------------------------------------------------------
CLIENT [rft_client_util.c:256:state:PS_RESEND_DATA]
Resending segment with sq: 14, file data: 35, checksum: -359007693
current retry: 1, max retries allowed: 20
payload:
of operating systems and networks.

-------------------------------------------------------------------------------
-------------------------------------------------------------------------------
CLIENT [rft_client_util.c:274:state:PS_ACK_WAIT]
Waiting for an ACK
-------------------------------------------------------------------------------
-------------------------------------------------------------------------------
CLIENT [rft_client_util.c:300:state:PS_ACK_RECV]
ACK with sq: 14 received
-------------------------------------------------------------------------------
-------------------------------------------------------------------------------
CLIENT [rft_client_util.c:256:state:PS_SEND_DATA]
Sending segment with sq: 15, file data: 35, checksum: 3358
current retry: 0, max retries allowed: 20
payload:

If you want to resolve performance
-------------------------------------------------------------------------------
-------------------------------------------------------------------------------
CLIENT [rft_client_util.c:274:state:PS_ACK_WAIT]
Waiting for an ACK
-------------------------------------------------------------------------------
-------------------------------------------------------------------------------
CLIENT [rft_client_util.c:300:state:PS_ACK_RECV]
ACK with sq: 15 received
-------------------------------------------------------------------------------
-------------------------------------------------------------------------------
CLIENT [rft_client_util.c:256:state:PS_SEND_DATA]
Sending segment with sq: 16, file data: 35, checksum: 3301
current retry: 0, max retries allowed: 20
payload:
 or reliability problems, you need 
-------------------------------------------------------------------------------
-------------------------------------------------------------------------------
CLIENT [rft_client_util.c:274:state:PS_ACK_WAIT]
Waiting for an ACK
-------------------------------------------------------------------------------
-------------------------------------------------------------------------------
CLIENT [rft_client_util.c:300:state:PS_ACK_RECV]
ACK with sq: 16 received
-------------------------------------------------------------------------------
-------------------------------------------------------------------------------
CLIENT [rft_client_util.c:256:state:PS_SEND_DATA]
Sending segment with sq: 17, file data: 35, checksum: 3268
current retry: 0, max retries allowed: 20
payload:
an understanding of the role of ope
-------------------------------------------------------------------------------
-------------------------------------------------------------------------------
CLIENT [rft_client_util.c:274:state:PS_ACK_WAIT]
Waiting for an ACK
-------------------------------------------------------------------------------
-------------------------------------------------------------------------------
CLIENT [rft_client_util.c:300:state:PS_ACK_RECV]
ACK with sq: 17 received
-------------------------------------------------------------------------------
-------------------------------------------------------------------------------
CLIENT [rft_client_util.c:256:state:PS_SEND_DATA]
Sending segment with sq: 18, file data: 30, checksum: 3302
current retry: 0, max retries allowed: 20
payload:
rating systems and networks.


-------------------------------------------------------------------------------
-------------------------------------------------------------------------------
CLIENT [rft_client_util.c:274:state:PS_ACK_WAIT]
Waiting for an ACK
-------------------------------------------------------------------------------
-------------------------------------------------------------------------------
CLIENT [rft_client_util.c:300:state:PS_ACK_RECV]
ACK with sq: 18 received
-------------------------------------------------------------------------------
-------------------------------------------------------------------------------
CLIENT [rft_client.c:90:state:PS_TFR_COMPLETE]
Transfer complete with expected bytes transferred
(bytes transferred == file size)
Total segments sent: 37, including: 18 resends
660 bytes sent for transfer of file: in660.txt of size: 660
-------------------------------------------------------------------------------
-------------------------------------------------------------------------------
