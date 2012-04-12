<?php

class MySQL {
	private $mysqli = false;

	public function __construct() {
		$this->Connect();
	}

	public function Connect() {
		if(!$this->mysqli) {
			$this->mysqli = new mysqli('localhost', 'lessent_website', 'SentiRoule2011', 'lessent_website');

			if($this->mysqli->connect_error) {
				throw new Exception('MySQL connection error ('.$this->mysqli->connect_errno.') : '.$this->mysqli->connect_error);
			}
		}
	}

	public function Query($query) {
		if(!$this->mysqli) $this->Connect();

		if(!$result = $this->mysqli->query($query)) {
			throw new Exception('MySQL error ('.$this->mysqli->errno.') : '.$this->mysqli->error);
		}

		return $result;
	}

        public function LastInsertId() {
	       if($this->mysqli) 
                        return $this->mysqli->insert_id;
               else
                        return false;
        }

	public function Prepare($query) {
		if(!$this->mysqli) $this->Connect();

		if(!$stmt = $this->mysqli->prepare($query)) {
			throw new Exception('MySQL error ('.$this->mysqli->errno.') : '.$this->mysqli->error);
		}

		return $stmt;
	}

	public function Close() {
		$this->mysqli->close();
		$this->mysqli = false;
	}
    
        public function EscapeString($string) {
	       return $this->mysqli->real_escape_string($string);
        }
}