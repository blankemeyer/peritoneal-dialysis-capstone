run-tests:
	pio test -e native

lint:
	pio check -e uno \
		--fail-on-defect high \
		--fail-on-defect medium \
		--fail-on-defect low
	clang-format --dry-run \
		$$(find src lib include test -regex ".*\.\(cpp\|h\)")

format:
	clang-format -i \
		$$(find src lib include test -regex ".*\.\(cpp\|h\)")

clean:
	pio run -e uno -t clean
	pio run -e native -t clean
