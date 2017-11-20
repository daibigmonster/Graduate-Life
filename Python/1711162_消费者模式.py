def consumer() :
    r = ''
    while True:
        n = yield r
        if not n :
            return
        print('[CONsumer] Consuming %s...' % n)
        r = '200 OK'