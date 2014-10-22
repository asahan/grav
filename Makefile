.PHONY: clean All

All:
	@echo "----------Building project:[ party - Debug ]----------"
	@cd "party" && $(MAKE) -f  "party.mk"
clean:
	@echo "----------Cleaning project:[ party - Debug ]----------"
	@cd "party" && $(MAKE) -f  "party.mk" clean
