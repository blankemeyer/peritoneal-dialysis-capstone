run_tests:
	pio test -e native

lint:
	clang-format --dry-run \
		$$(find src lib include test -regex ".*\.\(cpp\|h\)")

clean:
	pio run -e uno -t clean
	pio run -e native -t clean
