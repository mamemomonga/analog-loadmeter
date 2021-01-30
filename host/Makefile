APPNAME=cpuload-analogmeter
TARGETS= \
	bin/$(APPNAME)-darwin-amd64 \
	bin/$(APPNAME)-linux-amd64 \
	bin/$(APPNAME)-windows-amd64.exe

all: $(TARGETS)

bin/$(APPNAME)-darwin-amd64:
	GOOS=darwin GOARCH=amd64 go build -o $@ .

bin/$(APPNAME)-linux-amd64:
	GOOS=linux GOARCH=amd64 go build -o $@ .

bin/$(APPNAME)-windows-amd64.exe:
	GOOS=windows GOARCH=amd64 go build -o $@ .

clean:
	rm -f $(TARGETS)