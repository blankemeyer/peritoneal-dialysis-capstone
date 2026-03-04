run_tests:
	pio test -e native

clean:
	pio run -e uno -t clean
	pio run -e native -t clean
